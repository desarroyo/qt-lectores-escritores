# QT - Escritores y Lectores de un documento

## MTI - Programación paralela y multicore


Screenshot & Video Demo
-----------------------

##### Para ver el demo, click en la imagen (derecha). =>
<a style="float:right" href="https://vakito.com/mti/tarea-lectores_escritores.mp4" target="_blank">
  <img alt="PicSciP Demo Video" src="https://vakito.com/mti/screenshot-lectores_escritores.png" width="484" height="703" />
</a>

Implementar el problema de los lectores-escritores. Un archivo es compartido por varios procesos, distinguiéndose entre ellos dos tipos: 
	los lectores que sólo quieren leer la base de datos, y los escritores que quieren actualizar dicha base. Obviamente, si dos o más lectores acceden a la base de forma simultánea no existirá ningún conficto, sin embargo, si un escritor y algún otro escritor o lector acceden a la base de datos de manera simultánea, entonces si puede producir un conficto. 

Existen dos variantes: 
	que se le de prioridad a los lectores frente a los escritores (los lectores solo esperaran cuando exista un escritor escribiendo), o que se le de prioridad a los escritores frente a los lectores (si un escritor está esperando, ningún lector puede comenzar a leer).

Se debe adicionar el dato (numero secuencial y marca), al final del archivo.



### Todos

 - Documentar
 - Pruebas

License
----

MIT


**Software Libre! :)**