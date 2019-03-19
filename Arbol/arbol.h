#ifndef ARBOL_H
#define ARBOL_H

#include "nodo.h"

/*
 *  Incluyo <vector> para poder utilizar un vector en la funci�n de b�squeda en el �rbol
 *  Tambi�n incluyo iostream con el namespace est�ndar para poder utlizar string
 *  como par�metro en el prototipo de la funci�n BuscarNodoPrivado()
*/

#include<vector>
#include<iostream>
using namespace std;

class Loop;

class Arbol{
	private:
		Nodo* Raiz;
		int contador = 0;
		Loop* Kurisu;
	public:
		Arbol(): Raiz{nullptr} {}
		bool ArbolVacio();
		Nodo* CrearNodo(int n);
		void InsertarNodo(int n);
		void InsertarNodoPrivado(Nodo* nodo, int n);
		void VerPre();
		void PreOrden(Nodo* a);
		void VerIn();
		void InOrden(Nodo* a);
		void VerPost();
		void PostOrden(Nodo* a);
		void VerAlola();
		void Alola(Nodo* a, int n);
		int VerAltura();
		int Altura(Nodo* a);
		void BuscarNodo(int n);
		void BuscarNodoPrivado(Nodo* nodo, int n, vector<string> Flechas);
};

#endif
