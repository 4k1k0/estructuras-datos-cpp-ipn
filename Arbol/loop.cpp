#include "loop.h"

#include<iostream>
using namespace std;

#include<time.h>


void Loop::ingresar(){
	cout << endl << "Ingrese un numero: ";
	cin >> n;
	Kyou.InsertarNodo(n);
}
void Loop::mostrar(){
	limpiar();
	/* Checa si el árbol está vacío
	 * Si es así ejecuta las funciones para mostar los datos
	 * usando el objeto Kyou de la clase Árbol */
	if(!Kyou.ArbolVacio()){
		cout << "Pre-Orden" << endl;
		Kyou.VerPre();
		cout << endl << endl << "In-Orden" << endl;
		Kyou.VerIn();
		cout << endl << endl << "Post-Orden" << endl;
		Kyou.VerPost();
		cout << endl << endl << "Arbol Alola Form" << endl << endl;
		Kyou.VerAlola();
		h = Kyou.VerAltura();
		cout << endl << endl << "El arbol tiene una altura de " << h << " y una profundidad de " << h + 1 << endl;
	}
	else{
		cout << "El arbol esta vacio." << endl;
	}
	pausa();
}
void Loop::buscar(){
	if(!Kyou.ArbolVacio()){
		cout << endl << "Ingresa un numero para buscar: ";
		cin >> n;
		cout << endl << endl;
		Kyou.BuscarNodo(n);
	}
	else{
		cout << endl << "El arbol esta vacio." << endl;
	}
	pausa();
}
void Loop::limpiar(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
void Loop::pausa(){
	cout << endl << "Presione la tecla Enter para continuar...";
	cin.ignore().get();
}
void Loop::esperar(float segundos){
	#ifdef _WIN32
		segundos = segundos * 1000;
		int goal = (int) segundos + clock();
		while(goal > clock());
	#endif
}
void Loop::menu(){
	limpiar();
	cout << "1) Ingresar numero" <<
	endl << "2) Ver arbol" <<
	endl << "3) Buscar nodo" <<
	endl << "4) Salir" << endl;
	#ifdef _WIN32
		cout << "\257 ";
	#else
		cout << ">> ";
	#endif
	cin >> menuOp;
	
	switch(menuOp){
		case '1':
			ingresar();
			break;
		case '2':
			mostrar();
			break;
		case '3':
			buscar();
			break;
		case '4':
			r = 'N';
			break;
		default:
			limpiar();
			break;
	}
}
void Loop::loop(){
	while(r != 'N'){
		menu();
	}
}
