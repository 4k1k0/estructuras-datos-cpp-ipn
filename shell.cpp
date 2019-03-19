#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define MAX 7
/*
  Si a MAX le pongo 5 o
  si reemplazo la constante por una variable e.g. "¿Cuántos números quieres?   7"
  pasan cosas raras...
  Y no sé por qué lel
*/

main(){
	srand(time(NULL));
	int numeros[MAX];
	int interaciones, temporal;
	int ciclos, comprobaciones;
	ciclos = comprobaciones = 0;			// <--- Contadores para los ciclos y comprobaciones.
	
	for(int i = 0; i < MAX; i++){ 			// <--- Llenar el vector con números aleatorios.
		numeros[i] = (rand()%50) + 1;
	}
	
	cout << "Original:";				// <--- Mostrar el vector original.
	for(int i = 0; i < MAX; i++){
		cout << "\t" << numeros[i];
	}
	
	interaciones = MAX;
	int i;
	bool repetir;
	
	cout << endl;
	while(interaciones > 1){
		interaciones = (interaciones / 2);
		repetir = true;
		while(repetir == true){
			repetir = false;
			i = 0;
			while((i + interaciones) <= MAX){
				if(numeros[i] > numeros[i + interaciones]){
					temporal = numeros[i];
					numeros[i] = numeros[i + interaciones];
					numeros[i + interaciones] = temporal;
					cout << endl;
					repetir = true;
					ciclos++;
				}
				comprobaciones++;
				i++;
				cout << endl << "Ordenado:";					// <--- Mostrar el vector ordenado.
				for(int i = 0; i < MAX; i++){
					cout << "\t" << numeros[i];
				}
			}
		}
	}
	
	cout << endl << endl << "Comprobaciones: " << comprobaciones <<
	endl << "Ciclos: " << ciclos + 1 << endl;
	
}
