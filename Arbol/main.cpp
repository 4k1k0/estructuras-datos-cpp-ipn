/*
 *  Para compilar esto utilizando windows y DevC++ tienen que crear un nuevo proyecto,
 *  agregar los archivos .cpp y .h y modificar las instrucciones de compilaci�n del proyecto (click derecho>opciones de proyecto).
 *  Les dejo una captura de pantalla con lo que tienen que modificar.
 *
 *  Si los acentos se ven raros es problema de DevC++, creo que usa
 *  codificaci�n ANSI y yo escrib� esto con VIM usando utf-8
 *  
 *  El archivo Makefile es un script de compilaci�n de *nix
 *  Con Linux te ubicas en la carpeta donde est�n los archivos
 *  
 *  $ cd /la/ruta/de/los/archivos
 *  
 *  Y utilizas el comando make para compilar, esto leer� el archivo makefile
 *  e interpretar� sus instrucciones para generar el ejecutable.
 *  
 *  $ make
 *
 *  Puedes notar con el comando ls que ahora hay un archivo extra "Arbol"
 *  As� se ejecutas.
 *
 *  $ ./Arbol
 *
 *  Puedes ejecutar el par�metro clean al comando make para borrar el ejecutable.
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
