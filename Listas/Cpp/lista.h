#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista{
	private:
		int contador = 0;
		Nodo* Actual;
		Nodo* Cabeza; /* Pensar como Cabeza de un animal (Lista) */
		Nodo* Cola;   /* Pensar como Cola de un animal (Lista) */
		Nodo* Temporal;
	public:
		Lista(): Actual{NULL}, Cabeza{NULL}, Temporal{NULL} {}
		bool ListaVacia(){
			return(Cabeza == NULL);
		}
		
		void AgregarCola(int n){    /* Primero en entrar primero en salir */
			Actual = new Nodo(n);
			if(ListaVacia()){
				Cabeza = Actual;
				Cola = Actual;
				Temporal = Actual;
			}
			else{
				Temporal = Cabeza;
				while(Temporal->Siguiente){
					Temporal = Temporal->Siguiente;
				}
				Temporal->Siguiente = Actual;
				Temporal = Temporal->Siguiente;
			}
			contador++;
		}
		
		void AgregarPila(int n){    /* Primero en entrar ultimo en salir */
			Actual = new Nodo(n);
			if(ListaVacia()){
				Cabeza = Actual;
				Cola = Actual;
				Temporal = Actual;
			}
			else{
				Temporal = Actual;
				Temporal->Siguiente = Cabeza;
				Cabeza = Temporal;
			}
			contador++;
		}
		
		void AgregarDespues(int posicion, int n){
			Actual = new Nodo(n);
			if(!ListaVacia()){
				int cont = 1;
				Temporal = Cabeza;
				while((cont < posicion) && Temporal){
					Temporal = Temporal->Siguiente;
					cont++;
				}
				Actual->Siguiente = Temporal->Siguiente;
				Temporal->Siguiente = Actual;
			}
			contador++;
		}
		
		void Borrar(Nodo* ndo){
			delete ndo;
			contador--;
		}
		
		void BorrarCabeza(){ 				/* Elimar cabeza de la lista */
			if(!ListaVacia()){
				Nodo* Refuerzo;
				Refuerzo = Cabeza;
				Temporal = Cabeza;
				Cabeza = Temporal->Siguiente;
				Borrar(Refuerzo);
			}
		}
		
		void BorrarCola(){					/* Eliminar cola de la lista */
			if(!ListaVacia()){
				if(contador == 1){
					Nodo* Refuerzo = Cabeza;
					Cabeza = NULL;
					Borrar(Refuerzo);
				}
				else{
					Temporal = Cabeza;
					for(int i = 1; i < contador - 1; i++){
						Temporal = Temporal->Siguiente;
					}
					Nodo* Refuerzo;
					Refuerzo = Temporal->Siguiente;
					Temporal->Siguiente = NULL;
					Borrar(Refuerzo);
				}
			}
		}
		
		void BorrarEntre(int posicion){		/* Eliminar una posición de la lista */
			if(!ListaVacia()){
				int cont = 1;
				Temporal = Cabeza;
				while(cont < posicion - 1 && Temporal->Siguiente){
					Temporal = Temporal->Siguiente;
					cont++;
				}
				Nodo* Refuerzo;
				Refuerzo = Temporal->Siguiente;
				Temporal->Siguiente = Temporal->Siguiente->Siguiente;
				Borrar(Refuerzo);
			}
		}
		
		void BorrarLista(){
			if(!ListaVacia()){
				Temporal = Cabeza;
				while(Temporal){
					Nodo* Refuerzo;
					Refuerzo = Temporal;
					Temporal = Temporal->Siguiente;
					Borrar(Refuerzo);
				}
				Cabeza = NULL;
				contador = 0;
			}
		}
						
		void Mostrar(){
			if(contador <= 0){
				cout << "La lista esta vacia" << endl;
			}
			else{
				Temporal = Cabeza;
				int cont = 1;
				cout << "La lista es:" << endl;
				while(Temporal){
					cout << cont << ")\t" << Temporal->numero << endl;
					cont++;
					Temporal = Temporal->Siguiente;
				}
			}
		}
		
		int nElementos(){
			return contador;
		}
		
		
};

#endif
