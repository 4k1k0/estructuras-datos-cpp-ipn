#ifndef ARBOL_H
#define ARBOL_H

#include "nodo.h"

/*
 *  Incluyo <vector> para poder utilizar un vector en la función de búsqueda en el árbol
 *  También incluyo iostream con el namespace estándar para poder utlizar string
 *  como parámetro en el prototipo de la función BuscarNodoPrivado()
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
