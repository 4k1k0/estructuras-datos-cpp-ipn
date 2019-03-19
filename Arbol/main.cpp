/*
 *  Para compilar esto utilizando windows y DevC++ tienen que crear un nuevo proyecto,
 *  agregar los archivos .cpp y .h y modificar las instrucciones de compilación del proyecto (click derecho>opciones de proyecto).
 *  Les dejo una captura de pantalla con lo que tienen que modificar.
 *
 *  Si los acentos se ven raros es problema de DevC++, creo que usa
 *  codificación ANSI y yo escribí esto con VIM usando utf-8
 *  
 *  El archivo Makefile es un script de compilación de *nix
 *  Con Linux te ubicas en la carpeta donde están los archivos
 *  
 *  $ cd /la/ruta/de/los/archivos
 *  
 *  Y utilizas el comando make para compilar, esto leerá el archivo makefile
 *  e interpretará sus instrucciones para generar el ejecutable.
 *  
 *  $ make
 *
 *  Puedes notar con el comando ls que ahora hay un archivo extra "Arbol"
 *  Así se ejecutas.
 *
 *  $ ./Arbol
 *
 *  Puedes ejecutar el parámetro clean al comando make para borrar el ejecutable.
 *
 *  $ make clean
 *
 */
 
#include "loop.h"

int main(){
	Loop Marissa;
	Marissa.loop();
	return 0;
}
