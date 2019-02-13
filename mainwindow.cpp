#include <QMessageBox>
#include <QThread>
#include <QString>
#include <QDir>

#include "mainwindow.h"
#include "hilo_ui.h"
#include "hilo_abcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <QApplication>
#include <QMetaObject>
#include <qobjectdefs.h>
#include <QFile>
#include <QStringList>
#include <QDebug>

#ifdef _WIN32
#  include <windows.h>
#else
#  include <unistd.h>
#endif

int vel_a= 0;
int vel_b= 0;
int vel_c= 0;
int vel_d= 0;


int cont_a= 0;
int cont_b= 0;
int cont_c= 0;
int cont_d= 0;

int current_lectores= 0;

int lastId= 0;

HiloABCD *workerA;
HiloABCD *workerB;
QList<int> listLectores;
QList<int> listLectoresEsperando;
QList<int> listEscritoresEsperando;
QString currentEscritor = "N/A";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      infiniteCountRunning(false),
      countRunning(false)
{
    ui.setupUi(this);

    this->setWindowTitle("lectores-escritores");

    ui.lblLeyendo->setStyleSheet("QLabel { color : blue; }");
    ui.lblEscribiendo->setStyleSheet("QLabel { color : red; }");


    ui.lblHilo01_velocidad->setStyleSheet("QLabel { color : blue; }");
    ui.lblHilo02_velocidad->setStyleSheet("QLabel { color : red; }");

    ui.pbHilo01->setStyleSheet("QProgressBar {border: 2px solid grey;border-radius: 5px;background-color: #fbf3ec;}QProgressBar::chunk {background-color: #99d4d9;width: 20px;}");
    ui.pbHilo02->setStyleSheet("QProgressBar {border: 2px solid grey;border-radius: 5px;background-color: #fbf3ec;}QProgressBar::chunk {background-color: #daa482;width: 20px;}");

    vel_a = 1;
    ui.slLectores->setValue(vel_a);
    ui.pbHilo01->setValue(cont_a);

    vel_b = 0;
    ui.slEscritores->setValue(vel_b);
    ui.pbHilo02->setValue(cont_b);


    connectSignalsSlots();
}

int MainWindow::appendCSV(int id, QString marca){
    QFile file("./assets/datos.csv");


    if (file.open(QIODevice::Append)) {
        QString valor = ""+QString::number(id) + "," + marca + "\n";
        file.write(valor.toStdString().c_str());
        file.close();
     }

    abrirCSV();
}

int MainWindow::abrirCSV(){
    QString path = QDir::currentPath();

    QFile file("./assets/datos.csv");
       if (!file.open(QIODevice::ReadOnly)) {
           qDebug() << file.errorString();
           return 1;
       }


       ui.tblMarcas->setRowCount(0);
       ui.tblMarcas->clear();
       ui.tblMarcas->setHorizontalHeaderLabels( {"ID", "MARCA"} );

       QStringList wordList;
       int fila = 0;
       QTableWidgetItem pCell;
       while (!file.atEnd()) {
           fila = ui.tblMarcas->rowCount();
           ui.tblMarcas->insertRow( fila );
           QByteArray line = file.readLine();
           wordList.append(line.split(',').first());

           QTableWidgetItem *pCell = ui.tblMarcas->item(fila, 0);
           if(!pCell)
           {
               pCell = new QTableWidgetItem;
               ui.tblMarcas->setItem(fila, 0, pCell);
           }
           pCell->setText(line.split(',').first());

           pCell = ui.tblMarcas->item(fila, 1);
           if(!pCell)
           {
               pCell = new QTableWidgetItem;
               ui.tblMarcas->setItem(fila, 1, pCell);
           }
           pCell->setText(line.split(',').last());
           lastId = QString(line.split(',').first()).toInt();
       }
       file.close();

       //qDebug() << wordList;

       ui.tblMarcas->selectRow(ui.tblMarcas->rowCount()-1);
       ui.tblMarcas->scrollToBottom();

}

void MainWindow::updateCount(int cnt, int hilo)
{
    switch (hilo) {
        case 1:
            cont_a = cont_a+1;
            ui.pbHilo01->setValue(cont_a);
            break;
    case 2:
        cont_b = cont_b+1;
        ui.pbHilo02->setValue(cont_b);
        break;
    }

    if(cont_a >= 100){
        workerA->enEspera(true);
        workerA->velocidad( (rand() %10)+20);
        vel_a = 0;
        current_lectores = 0;
        ui.slLectores->setValue(vel_a);
        ui.lblLeyendo->setText(QString::number(0)+ " estan leyendo ...");


            if(listLectores.size() > 0){
                listLectores.clear();
            }

        formaHtml("Lectores terminaron de leer... ");

        reiniciaLector();
    }

    if(cont_b >= 100){
        workerB->enEspera(true);
        lastId++;
        appendCSV(lastId, "Marca-"+QString::number(lastId));
        workerB->velocidad( (rand() %20)+10);
        ui.lblEscribiendo->setText(QString::number(0)+ " esta escribiendo ...");

        currentEscritor = "N/A";
        formaHtml("El escritor terminò de escribir el registro #"+QString::number(lastId)+"... ");

        //vel_b = vel_b -1;
        //ui.slEscritores->setValue(vel_b);
        reiniciaEscritor();
    }

}

void MainWindow::reinicia(){


    cont_a= 0;
    ui.pbHilo01->setValue(cont_a);

    cont_b= 0;
    ui.pbHilo02->setValue(cont_b);



    ui.lblLeyendo->setText(QString::number(0)+ " estan leyendo ...");
    ui.lblEscribiendo->setText(QString::number(0)+ " esta escribiendo ...");

    currentEscritor = "N/A";
    listLectores.clear();
    listLectoresEsperando.clear();
    listEscritoresEsperando.clear();

    vel_a = 0;
    ui.slLectores->setValue(vel_a);

    vel_b = 0;
    ui.slEscritores->setValue(vel_b);

    formaHtml("Iniciando...");

    abrirCSV();
}

void MainWindow::reiniciaLector(){
    cont_a= 0;
    ui.pbHilo01->setValue(cont_a);

}

void MainWindow::reiniciaEscritor(){
    cont_b= 0;
    ui.pbHilo02->setValue(cont_b);

}

void MainWindow::updateInfiniteCount(int cnt)
{
    ui.lblCount->setText(QString::number(cnt)+" seg.");

    if((rand() %100) > 75){

        int lectoresNuevos = (rand() %5);
        int idLector = -1;

        for (int var = 0; var < lectoresNuevos; ++var) {
           idLector = (rand() %500);

           listLectoresEsperando.append(idLector);
           formaHtml("Llegaron "+QString::number(lectoresNuevos)+" lectores...");
        }


        vel_a = ui.slLectores->value() + (lectoresNuevos);
        ui.slLectores->setValue(vel_a);
    }
    if((rand() %100) > 85 and vel_b < 10){

        int escritoresNuevos = (rand() %3);
        int idEscritor = -1;

        for (int var = 0; var < escritoresNuevos; ++var) {
           idEscritor = (rand() %500);

           listEscritoresEsperando.append(idEscritor);
           formaHtml("Llegaron "+QString::number(escritoresNuevos)+" escritores...");
        }

        vel_b = ui.slEscritores->value() + (escritoresNuevos);
        ui.slEscritores->setValue(vel_b);
    }




    if(workerB->isEsperando() && ui.slLectores->value() > 0 ){
            workerA->enEspera(false);
            workerB->enEspera(true);
            current_lectores = current_lectores + ui.slLectores->value();
            ui.lblLeyendo->setText(QString::number(current_lectores)+ " leyendo "+"[Marca #"+QString::number(lastId)+"]");

            for (int var = 0; var < ui.slLectores->value(); ++var) {
                if(listLectoresEsperando.size() > 0){
                    listLectores.append(listLectoresEsperando.first());
                    listLectoresEsperando.removeFirst();
                }
            }

            formaHtml("");


            vel_a = 0;
            ui.slLectores->setValue(vel_a);
     }
     else if(workerB->isEsperando() && workerA->isEsperando() && ui.slEscritores->value() > 0 && ui.slLectores->value() <= 0 ){
        workerB->enEspera(false);
        workerA->enEspera(true);
        ui.lblEscribiendo->setText(QString::number(1)+ " esta escribiendo ...");       

        currentEscritor = "Escritor ("+QString::number(listEscritoresEsperando.first())+")";
        if(listEscritoresEsperando.size() > 0){
            listEscritoresEsperando.removeFirst();
        }

        formaHtml("");

        vel_b = vel_b -1;
        ui.slEscritores->setValue(vel_b);

    }
}



void MainWindow::startCount()
{
    reinicia();

    QThread  *workerThreadA;
    QThread  *workerThreadB;



    if (countRunning) {
        QMessageBox::critical(this, "Error", "Los Hilos ya estan corriendo!");
        return;
    }

    workerThreadA = new QThread;
    workerThreadB = new QThread;

    workerA       = new HiloABCD(1, (rand() %100)+50, 0, 100, true);
    workerB       = new HiloABCD(2, (rand() %100)+50, 0, 100, true);


    workerA->moveToThread(workerThreadA);
    workerB->moveToThread(workerThreadB);

    connect(workerThreadA, SIGNAL(started()), workerA, SLOT(doWork()));
    connect(workerThreadB, SIGNAL(started()), workerB, SLOT(doWork()));
    connect(workerA, SIGNAL(finished()), workerThreadA, SLOT(quit()));
    connect(workerB, SIGNAL(finished()), workerThreadB, SLOT(quit()));

    connect(workerA, SIGNAL(finished()), workerA, SLOT(deleteLater()));
    connect(workerB, SIGNAL(finished()), workerB, SLOT(deleteLater()));

    connect(workerA, SIGNAL(finished()), this, SLOT(countFinished()));
    connect(workerB, SIGNAL(finished()), this, SLOT(countFinished()));

    connect(workerThreadA, SIGNAL(finished()), workerThreadA, SLOT(deleteLater()));
    connect(workerThreadB, SIGNAL(finished()), workerThreadB, SLOT(deleteLater()));

    connect(workerA, SIGNAL(updateCount(int, int)), this, SLOT(updateCount(int, int)));
    connect(workerB, SIGNAL(updateCount(int, int)), this, SLOT(updateCount(int, int)));

    connect(ui.btnStop, SIGNAL(clicked()), workerA, SLOT(stopWork()));
    connect(ui.btnStop, SIGNAL(clicked()), workerB, SLOT(stopWork()));

    workerThreadA->start();
    workerThreadB->start();

    countRunning = true;
}

void MainWindow::startInfiniteCount()
{
    QThread             *workerThread;
    HiloUI *worker;

    if (infiniteCountRunning) {
        QMessageBox::critical(this, "Error", "El hilo de UI ya esta corriendo!");
        return;
    }

    workerThread = new QThread;
    worker       = new HiloUI;
    worker->moveToThread(workerThread);
    connect(workerThread, SIGNAL(started()), worker, SLOT(doWork()));
    connect(worker, SIGNAL(finished()), workerThread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
    connect(worker, SIGNAL(finished()), this, SLOT(infiniteCountFinished()));
    connect(worker, SIGNAL(updateCount(int)), this, SLOT(updateInfiniteCount(int)));
    connect(ui.btnStop, SIGNAL(clicked()), worker, SLOT(stopWork()));
    workerThread->start();

    infiniteCountRunning = true;

}

void MainWindow::countFinished()
{
    countRunning = false;

   reinicia();
}

void MainWindow::infiniteCountFinished()
{
    infiniteCountRunning = false;
    cont_a= 0;
    ui.pbHilo01->setValue(cont_a);
}

void MainWindow::connectSignalsSlots()
{
    connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(startInfiniteCount()));
    connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(startCount()));
}


void MainWindow::actualizaVelocidadHilo(){
    if(workerA){
        workerA->velocidad((rand() %50)+20);
    }
    if(workerB){
        workerB->velocidad((rand() %40)+10);
    }
}


void MainWindow::on_slLectores_valueChanged(int value)
{
    vel_a = value;
    ui.lblHilo01_velocidad->setText(QString::number(value));
}

void MainWindow::on_slEscritores_valueChanged(int value)
{
    vel_b = value;
    ui.lblHilo02_velocidad->setText(QString::number(value));
}

void MainWindow::formaHtml(QString mensaje){
    QString html = "<h3 style=\"color: #2e6c80;\">Log</h3>\n"
                   "<hr>\n"
                    "<h5 style=\"color: #54455c;\">Lectores en Espera ("+QString::number(listLectoresEsperando.size())+"):</h5>\n"
                    "<ul style=\"list-style-type: square; color: #2f285e;\">\n";

    for(int lector : listLectoresEsperando){
        html = html +
            "<li>Lector ("+QString::number(lector)+")</li>\n";
    }

    html = html + "</ul>\n"
                  "<h5 style=\"color: #54455c;\">Escritores en Espera ("+QString::number(listEscritoresEsperando.size())+"):</h5>\n"
                  "<ul style=\"list-style-type: square; color: #2f285e;\">\n";

    for(int escritor : listEscritoresEsperando){
        html = html +
            "<li>Escritor ("+QString::number(escritor)+")</li>\n";
    }



    html = html +
        "</ul>\n"
        "<hr>\n"
        "<h4 style=\"color: #085076;\">Leyendo ("+QString::number(listLectores.size())+"):</h5>\n"
        "<ul style=\"list-style-type: square; color: #2f285e;\">\n"
            ;

    for(int lector : listLectores){
        html = html +
            "<li>Lector ("+QString::number(lector)+") [Marca #"+QString::number(lastId)+"]</li>\n";
    }

    html = html +
        "</ul>\n"
        "<h4 style=\"color: #085076;\">Escribiendo:</h5>\n"
        "<ul style=\"list-style-type: square; color: #2f285e;\">\n"
        "<li>"+currentEscritor+"</li>\n"
        "</ul>\n"
        ;


    html = html +
            "<hr>\n"
            "<h6 style=\"color: #54455c;\">"+mensaje+"</h6>\n";

    ui.txtLog->setHtml(html);


}

