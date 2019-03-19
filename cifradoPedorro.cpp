#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class programa{
	private:
		int cont1, cont2;
		char cad1[100];
		char cad2[100];
		char cad3[100];
	public:
		void ingresar();
		void ordenar();
		void imprimir();
		void loop();
};

main(){
	programa verga;
	verga.loop();
}


void programa::ingresar(){
	cout << "Ingresa un mensaje: ";
	cin.get(cad1, 100);
}
void programa::ordenar(){
	cont1 = cont2 = 0;
	for(int i = 0; i < strlen(cad1); i++){
		if((i % 2) != 0){
			cad2[cont1] = cad1[i];
			cont1++;	
		}
		else if((i % 2) == 0){
			cad3[cont2] = cad1[i];
			cont2++;
		}
	}
}
void programa::imprimir(){
	int largo2 = cont1;
	int largo3 = cont2;
	cout << endl << "Mensaje original: " << endl;
	for(int i = 0; i < strlen(cad1); i++){
		cout << cad1[i];
	}
	
	cout << endl << "Numeros nones: " << endl;
	for(int i = 0; i < cont1; i++){
		cout << cad2[i];
	}
	
	
	cout << endl << "Numeros pares: " << endl;
	for(int i = 0; i < cont2; i++){
		cout << cad3[i];
	}
	cout << endl << endl;
	
}
void programa::loop(){
	system("clear");
	ingresar();
	ordenar();
	imprimir();
}
