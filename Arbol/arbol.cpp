#include "arbol.h"

#include "loop.h"

/*
 *  Incluyo iostream con el namespace stándar para 
 *  utilizar cout en las funciones de mostrar el
 *  árbol y en la de búsqueda.
*/

#include<iostream>
using namespace std;



bool Arbol::ArbolVacio(){
	return Raiz == NULL;
}
	
Nodo* Arbol::CrearNodo(int n){
	Nodo* a = new Nodo(n);
	contador++;
	return a;
}
		
void Arbol::InsertarNodo(int n){
	InsertarNodoPrivado(Raiz, n);
}
		
void Arbol::InsertarNodoPrivado(Nodo* nodo, int n){
	if(ArbolVacio()){
		Raiz = CrearNodo(n);
	}
	else if(n < nodo->dato){
		if(nodo->Izquierda != NULL){
			InsertarNodoPrivado(nodo->Izquierda, n);
		}
		else{
			nodo->Izquierda = CrearNodo(n);	
		}
	}
	else if(n > nodo->dato){
		if(nodo->Derecha != NULL){
			InsertarNodoPrivado(nodo->Derecha, n);
		}
		else{
			nodo->Derecha = CrearNodo(n);
		}
	}
}

void Arbol::VerPre(){
	PreOrden(Raiz);
}

void Arbol::PreOrden(Nodo* a){
	if(a != NULL){
		cout << a->dato << " ";
		PreOrden(a->Izquierda);
		PreOrden(a->Derecha);
	}
}
		
void Arbol::VerIn(){
	InOrden(Raiz);
}
		
void Arbol::InOrden(Nodo* a){
	if(a->Izquierda != NULL){
		InOrden(a->Izquierda);
	}
	cout << a->dato << " ";
	if(a->Derecha != NULL){
		InOrden(a->Derecha);
	}
}
		
void Arbol::VerPost(){
	PostOrden(Raiz);
}
		
void Arbol::PostOrden(Nodo* a){
	if(a != NULL){
		PostOrden(a->Izquierda);
		PostOrden(a->Derecha);
		cout << a->dato << " ";
	}
}
		
void Arbol::VerAlola(){
	Alola(Raiz, contador);
}

void Arbol::Alola(Nodo* a, int n){
	if(a != NULL){
		Alola(a->Derecha, n+1);
		for(int i = 0; i < n; i++)
			cout << " ";
		Kurisu->esperar(0.2);
		cout << a->dato << endl;
		Alola(a->Izquierda, n+1);
	}
}
		
int Arbol::VerAltura(){
	return Altura(Raiz);
}

int Arbol::Altura(Nodo* a){
	int AltIzq, AltDer;
	if(a == NULL)
		return -1;
	else{
		AltIzq = Altura(a->Izquierda);
		AltDer = Altura(a->Derecha);
		return (AltIzq > AltDer) ? AltIzq + 1 : AltDer + 1;
	}
	return 0;	
}

/* 
 * Los vectores dinámicos de C++ son similares a las listas enlazadas;
 * no necesitan que se les asigne un valor estático como a los arreglos
 * char arreglo[valor] ya que el valor de estos no puede cambiar durante
 * la ejecución. El vector permite llenar de "Izquierda->" y "Derecha->"
 * según lo requiera el árbol.
 */
		
void Arbol::BuscarNodo(int n){
	vector<string> Flechas;
	BuscarNodoPrivado(Raiz, n, Flechas);
}
		
void Arbol::BuscarNodoPrivado(Nodo* nodo, int n, vector<string> Flechas){
	if(!ArbolVacio()){
		if(n < nodo->dato){
			if(nodo->Izquierda != NULL){
				Flechas.push_back("Izquierda->");
				BuscarNodoPrivado(nodo->Izquierda, n, Flechas);
			}
		}
		else if(n > nodo->dato){
			if(nodo->Derecha != NULL){
				Flechas.push_back("Derecha->");
				BuscarNodoPrivado(nodo->Derecha, n, Flechas);
			}
		}
		if(n == nodo->dato){
			for(int i = 0; i < Flechas.size(); i++)
				cout << Flechas[i];
			cout << "[" << n << "]" << endl;
		}
		if(n != nodo->dato && nodo->Izquierda == NULL && nodo->Derecha == NULL)
			cout << n << " no existe en el arbol." << endl;
	}
}
