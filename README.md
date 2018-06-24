---
title: "Coloracion de Mapas en R"
output: html_document
---
#### Proyecto de Introduccion a la Inteligencia Artificial

##### Para la replica de los resultados del proyecto, se requiere de forma indispensable:

- Windows en cualquiera de las versiones:  9x/ME/NT4.0/2000/XP/2003/Vista/7/8/2012 Server/8.1 .

- R para Windows, version superior a 3.3.0 .

- Entorno de desarrollo RStdio .

Explicaremos la instalacion de R y Rstdio:

#### Instalacion de R version 3.5.0 o su versi?n m?s reciente:

1. Acceda al siguiente link: https://cran.r-project.org/bin/windows/base/, a continuacion seleccione la opcion "Download R 3.5.0 for Windows" .
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(9).png)


2. Ejecutar el archivo "R-3.5.0-win.exe" y proceder la instalaci?n segun los pasos que se le indican.

![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(13).png)



3. Finalizamos la instalacion, verificaremos su instalacion correcta luego de instalar RStdio.

#### Instalacion del entorno de desarrollo RStdio:

1. Acceda a la pagina principal de RStdio con el siguiente Link: https://www.rstudio.com/products/rstudio/download/ y descargue el instalador mas apropiado para su configuracion de hardware.

![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(11).png)


2. Ejecutar el archivo "RStdio-1.1.453.exe" generado y proceder la instalaci?n segun los pasos que se le indican.

![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(16).png)



#### Descargar el contenido del proyecto:

1. Acceda al repositorio de nuestro proyecto que se encuentra en Github, hagalo mediante el siguiente link: https://github.com/marcoleonrios/Estadistica20181/tree/master, a continuaci?n seleccione la opcion "Clone or download", acto seguido poceda a seleccionar Download ZIP.
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(12).png)

2. Luego de descargar el archivo, proceda a extraer el archivo en el directorio de su preferencia, luego de ello , ingrese a la carpeta "Estadistica20181-master" generada.
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(14).png)

3. Acceda a la carpeta "C?digo"
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(15).png)

4. Abra el archivo "codigo_proyecto.R" con RStdio.
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(18).png)

5. Sombree todo el c?digo y seleccione la opcion "Run"
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(31).png)
6. Espere que se instalen las librerias "rgdal" y "rgeos", luego de ello aparecera una ventana de seleccion de archivo, con la finalidad de escoger nuestro mapa.
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(23).png)

7. Buscamos la carpeta Pruebas_mapas que se encuentra en el mismo directorio que nuestro codigo.
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(24).png)
luego, elegimos el mapa que deseemos
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(25).png)
Para la seleccion tomada,buscamos un archivo con terminacion .shp, aqui se alojan los poligonos de nuestro mapa sin colorear, a continuacion seleccionamos abrir.
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(27).png)
Finalmente obtenemos:
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(28).png)
NUESTRO MAPA PINTADO!!
![](https://github.com/PatrichsInocenteCM274/Discreta/blob/master/imagenes/Captura%20de%20pantalla%20(30).png)


