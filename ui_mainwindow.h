/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupHilos;
    QPushButton *btnStop;
    QLabel *lblCount;
    QLabel *lblEscribiendo;
    QLabel *lblms;
    QLabel *lblminslider_3;
    QLabel *lblminslider_4;
    QPushButton *btnStart;
    QLabel *lblLeyendo;
    QLabel *lblminslider_2;
    QSlider *slEscritores;
    QLabel *lblHilo02_velocidad;
    QProgressBar *pbHilo02;
    QLabel *lblms_2;
    QSlider *slLectores;
    QProgressBar *pbHilo01;
    QLabel *lblminslider;
    QLabel *lblHilo01_velocidad;
    QPushButton *btnRandom;
    QLabel *label;
    QLabel *lblTiempoTranscurrido;
    QTableWidget *tblMarcas;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(481, 670);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupHilos = new QGroupBox(centralwidget);
        groupHilos->setObjectName(QString::fromUtf8("groupHilos"));
        btnStop = new QPushButton(groupHilos);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setGeometry(QRect(400, 600, 51, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8("assets/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon);
        btnStop->setIconSize(QSize(30, 30));
        lblCount = new QLabel(groupHilos);
        lblCount->setObjectName(QString::fromUtf8("lblCount"));
        lblCount->setGeometry(QRect(410, 20, 51, 31));
        lblCount->setLayoutDirection(Qt::RightToLeft);
        lblCount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblEscribiendo = new QLabel(groupHilos);
        lblEscribiendo->setObjectName(QString::fromUtf8("lblEscribiendo"));
        lblEscribiendo->setGeometry(QRect(190, 170, 231, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Black"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lblEscribiendo->setFont(font);
        lblEscribiendo->setFrameShape(QFrame::NoFrame);
        lblEscribiendo->setFrameShadow(QFrame::Raised);
        lblEscribiendo->setMidLineWidth(0);
        lblEscribiendo->setTextFormat(Qt::PlainText);
        lblEscribiendo->setMargin(5);
        lblms = new QLabel(groupHilos);
        lblms->setObjectName(QString::fromUtf8("lblms"));
        lblms->setGeometry(QRect(10, 60, 131, 31));
        lblms->setFont(font);
        lblms->setFrameShape(QFrame::NoFrame);
        lblms->setFrameShadow(QFrame::Raised);
        lblms->setMidLineWidth(0);
        lblms->setTextFormat(Qt::PlainText);
        lblms->setMargin(5);
        lblminslider_3 = new QLabel(groupHilos);
        lblminslider_3->setObjectName(QString::fromUtf8("lblminslider_3"));
        lblminslider_3->setGeometry(QRect(150, 180, 31, 21));
        lblminslider_3->setLayoutDirection(Qt::LeftToRight);
        lblminslider_3->setFrameShape(QFrame::NoFrame);
        lblminslider_3->setFrameShadow(QFrame::Raised);
        lblminslider_3->setMidLineWidth(0);
        lblminslider_3->setTextFormat(Qt::PlainText);
        lblminslider_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblminslider_3->setMargin(5);
        lblminslider_4 = new QLabel(groupHilos);
        lblminslider_4->setObjectName(QString::fromUtf8("lblminslider_4"));
        lblminslider_4->setGeometry(QRect(10, 180, 21, 21));
        lblminslider_4->setLayoutDirection(Qt::LeftToRight);
        lblminslider_4->setFrameShape(QFrame::NoFrame);
        lblminslider_4->setFrameShadow(QFrame::Raised);
        lblminslider_4->setMidLineWidth(0);
        lblminslider_4->setTextFormat(Qt::PlainText);
        lblminslider_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblminslider_4->setMargin(5);
        btnStart = new QPushButton(groupHilos);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setGeometry(QRect(280, 600, 111, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("OCR A Extended"));
        font1.setPointSize(12);
        btnStart->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("assets/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStart->setIcon(icon1);
        lblLeyendo = new QLabel(groupHilos);
        lblLeyendo->setObjectName(QString::fromUtf8("lblLeyendo"));
        lblLeyendo->setGeometry(QRect(190, 90, 231, 31));
        lblLeyendo->setFont(font);
        lblLeyendo->setFrameShape(QFrame::NoFrame);
        lblLeyendo->setFrameShadow(QFrame::Raised);
        lblLeyendo->setMidLineWidth(0);
        lblLeyendo->setTextFormat(Qt::PlainText);
        lblLeyendo->setMargin(5);
        lblminslider_2 = new QLabel(groupHilos);
        lblminslider_2->setObjectName(QString::fromUtf8("lblminslider_2"));
        lblminslider_2->setGeometry(QRect(150, 100, 31, 21));
        lblminslider_2->setLayoutDirection(Qt::LeftToRight);
        lblminslider_2->setFrameShape(QFrame::NoFrame);
        lblminslider_2->setFrameShadow(QFrame::Raised);
        lblminslider_2->setMidLineWidth(0);
        lblminslider_2->setTextFormat(Qt::PlainText);
        lblminslider_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblminslider_2->setMargin(5);
        slEscritores = new QSlider(groupHilos);
        slEscritores->setObjectName(QString::fromUtf8("slEscritores"));
        slEscritores->setGeometry(QRect(30, 180, 121, 22));
        slEscritores->setMinimum(0);
        slEscritores->setMaximum(20);
        slEscritores->setSingleStep(1);
        slEscritores->setPageStep(1);
        slEscritores->setValue(0);
        slEscritores->setTracking(true);
        slEscritores->setOrientation(Qt::Horizontal);
        slEscritores->setTickInterval(1);
        lblHilo02_velocidad = new QLabel(groupHilos);
        lblHilo02_velocidad->setObjectName(QString::fromUtf8("lblHilo02_velocidad"));
        lblHilo02_velocidad->setGeometry(QRect(130, 140, 51, 31));
        lblHilo02_velocidad->setFont(font);
        lblHilo02_velocidad->setLayoutDirection(Qt::LeftToRight);
        lblHilo02_velocidad->setFrameShape(QFrame::NoFrame);
        lblHilo02_velocidad->setFrameShadow(QFrame::Raised);
        lblHilo02_velocidad->setMidLineWidth(0);
        lblHilo02_velocidad->setTextFormat(Qt::PlainText);
        lblHilo02_velocidad->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblHilo02_velocidad->setMargin(5);
        pbHilo02 = new QProgressBar(groupHilos);
        pbHilo02->setObjectName(QString::fromUtf8("pbHilo02"));
        pbHilo02->setGeometry(QRect(190, 170, 261, 31));
        pbHilo02->setValue(100);
        lblms_2 = new QLabel(groupHilos);
        lblms_2->setObjectName(QString::fromUtf8("lblms_2"));
        lblms_2->setGeometry(QRect(10, 140, 141, 31));
        lblms_2->setFont(font);
        lblms_2->setFrameShape(QFrame::NoFrame);
        lblms_2->setFrameShadow(QFrame::Raised);
        lblms_2->setMidLineWidth(0);
        lblms_2->setTextFormat(Qt::PlainText);
        lblms_2->setMargin(5);
        slLectores = new QSlider(groupHilos);
        slLectores->setObjectName(QString::fromUtf8("slLectores"));
        slLectores->setGeometry(QRect(30, 100, 121, 22));
        slLectores->setMinimum(0);
        slLectores->setMaximum(20);
        slLectores->setSingleStep(1);
        slLectores->setPageStep(1);
        slLectores->setValue(0);
        slLectores->setTracking(true);
        slLectores->setOrientation(Qt::Horizontal);
        slLectores->setTickInterval(1);
        pbHilo01 = new QProgressBar(groupHilos);
        pbHilo01->setObjectName(QString::fromUtf8("pbHilo01"));
        pbHilo01->setGeometry(QRect(190, 92, 261, 31));
        pbHilo01->setValue(100);
        lblminslider = new QLabel(groupHilos);
        lblminslider->setObjectName(QString::fromUtf8("lblminslider"));
        lblminslider->setGeometry(QRect(10, 100, 21, 21));
        lblminslider->setLayoutDirection(Qt::LeftToRight);
        lblminslider->setFrameShape(QFrame::NoFrame);
        lblminslider->setFrameShadow(QFrame::Raised);
        lblminslider->setMidLineWidth(0);
        lblminslider->setTextFormat(Qt::PlainText);
        lblminslider->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblminslider->setMargin(5);
        lblHilo01_velocidad = new QLabel(groupHilos);
        lblHilo01_velocidad->setObjectName(QString::fromUtf8("lblHilo01_velocidad"));
        lblHilo01_velocidad->setGeometry(QRect(130, 60, 51, 31));
        lblHilo01_velocidad->setFont(font);
        lblHilo01_velocidad->setLayoutDirection(Qt::LeftToRight);
        lblHilo01_velocidad->setFrameShape(QFrame::NoFrame);
        lblHilo01_velocidad->setFrameShadow(QFrame::Raised);
        lblHilo01_velocidad->setMidLineWidth(0);
        lblHilo01_velocidad->setTextFormat(Qt::PlainText);
        lblHilo01_velocidad->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblHilo01_velocidad->setMargin(5);
        btnRandom = new QPushButton(groupHilos);
        btnRandom->setObjectName(QString::fromUtf8("btnRandom"));
        btnRandom->setGeometry(QRect(280, 570, 171, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("assets/random.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRandom->setIcon(icon2);
        btnRandom->setCheckable(false);
        label = new QLabel(groupHilos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 261, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("November"));
        font2.setPointSize(12);
        label->setFont(font2);
        lblTiempoTranscurrido = new QLabel(groupHilos);
        lblTiempoTranscurrido->setObjectName(QString::fromUtf8("lblTiempoTranscurrido"));
        lblTiempoTranscurrido->setGeometry(QRect(350, 0, 111, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(7);
        lblTiempoTranscurrido->setFont(font3);
        lblTiempoTranscurrido->setLayoutDirection(Qt::RightToLeft);
        lblTiempoTranscurrido->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tblMarcas = new QTableWidget(groupHilos);
        if (tblMarcas->columnCount() < 2)
            tblMarcas->setColumnCount(2);
        tblMarcas->setObjectName(QString::fromUtf8("tblMarcas"));
        tblMarcas->setGeometry(QRect(10, 250, 256, 391));
        tblMarcas->setColumnCount(2);
        label_2 = new QLabel(groupHilos);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 220, 261, 21));
        label_2->setFont(font2);
        pbHilo01->raise();
        pbHilo02->raise();
        btnStop->raise();
        lblCount->raise();
        lblEscribiendo->raise();
        lblms->raise();
        lblminslider_3->raise();
        lblminslider_4->raise();
        btnStart->raise();
        lblLeyendo->raise();
        lblminslider_2->raise();
        slEscritores->raise();
        lblHilo02_velocidad->raise();
        lblms_2->raise();
        slLectores->raise();
        lblminslider->raise();
        lblHilo01_velocidad->raise();
        btnRandom->raise();
        label->raise();
        lblTiempoTranscurrido->raise();
        tblMarcas->raise();
        label_2->raise();

        verticalLayout->addWidget(groupHilos);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Threader", nullptr));
        groupHilos->setTitle(QApplication::translate("MainWindow", "Biblioteca / Lectores y Escritores", nullptr));
        btnStop->setText(QString());
        lblCount->setText(QApplication::translate("MainWindow", "0", nullptr));
        lblEscribiendo->setText(QApplication::translate("MainWindow", "0 Escribiendo...", nullptr));
        lblms->setText(QApplication::translate("MainWindow", "Lectores en Espera", nullptr));
        lblminslider_3->setText(QApplication::translate("MainWindow", "20", nullptr));
        lblminslider_4->setText(QApplication::translate("MainWindow", "0", nullptr));
        btnStart->setText(QApplication::translate("MainWindow", "Comenzar", nullptr));
        lblLeyendo->setText(QApplication::translate("MainWindow", "0 Leyendo ...", nullptr));
        lblminslider_2->setText(QApplication::translate("MainWindow", "20", nullptr));
        lblHilo02_velocidad->setText(QApplication::translate("MainWindow", "0", nullptr));
        pbHilo02->setFormat(QString());
        lblms_2->setText(QApplication::translate("MainWindow", "Escritores en Espera", nullptr));
        pbHilo01->setFormat(QString());
        lblminslider->setText(QApplication::translate("MainWindow", "0", nullptr));
        lblHilo01_velocidad->setText(QApplication::translate("MainWindow", "0", nullptr));
        btnRandom->setText(QApplication::translate("MainWindow", "Valores Aleatorios", nullptr));
        label->setText(QApplication::translate("MainWindow", "Estatus", nullptr));
        lblTiempoTranscurrido->setText(QApplication::translate("MainWindow", "Tiempo transcurrido", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Libro Marcas de Carros", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
