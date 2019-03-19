#ifndef LOOP_H
#define LOOP_H

#include "lista.h"

class programa{
	private:
		char r = 'S';
		int numero;
		int menuOP;
		int pos;
		Lista Kumiko;
	public:
		void addCola(){
			cout << "Ingresa un numero: ";
			cin >> numero;
			Kumiko.AgregarCola(numero);
		}
		
		void addPila(){
			cout << "Ingresa un numero: ";
			cin >> numero;
			Kumiko.AgregarPila(numero);
		}
		
		void addEntre(){
			limpiar();
			Kumiko.Mostrar();
			cout << endl << "Elige una posicion: ";
			cin >> pos;
			cout << "Ingresa un numero: ";
			cin >> numero;
			Kumiko.AgregarDespues(pos, numero);
		}
		
		void verLista(){
			limpiar();
			Kumiko.Mostrar();
			pausa();
		}
		
		void borrarCabeza(){
			if(Kumiko.ListaVacia() == false){
				cout << endl << "Se ha eliminado el primer elemento de la lista." << endl;
				Kumiko.BorrarCabeza();
			}
			else{
				limpiar();
				cout << "La lista esta vacia" << endl;
			}
			pausa();
		}
		
		void borrarCola(){
			if(Kumiko.ListaVacia() == false){
				cout << endl << "Se ha eliminado el ultimo elemento de la lista." << endl;
				Kumiko.BorrarCola();
			}
			else{
				limpiar();
				cout << "La lista esta vacia" << endl;
			}
			pausa();
		}
		
		void borrarEntre(){
			limpiar();
			if(Kumiko.ListaVacia() == false){
				Kumiko.Mostrar();
				cout << endl << "Elige una posicion: ";
				cin >> pos;
				Kumiko.BorrarEntre(pos);
			}
			else{
				cout << "La lista esta vacia" << endl;
				pausa();
			}		
		}
		
		void limpiar(){
			#ifdef _WIN32
				system("cls");
			#else
				system("clear");
			#endif
		}
		
		void pausa(){
			cout << "Presione la tecla Enter para continuar...";
			cin.ignore().get();
		}
		
		void menu(){
			limpiar();
			
			cout << "1) Agregar Cola" <<
			endl << "2) Agregar Pila" <<
			endl << "3) Agregar despues de" <<
			endl << "4) Borrar primer elemento" <<
			endl << "5) Borrar ultimo elemento" <<
			endl << "6) Borrar elemento de la lista" <<
			endl << "7) Borrar lista" <<
			endl << "8) Mostrar lista" <<
			endl << "9) Mostrar numero de elementos" <<
			endl << "10) Salir" << endl <<
			endl << "\257  ";
			cin >> menuOP;
			
			switch(menuOP){
				case 1:
					addCola();
					break;
				case 2:
					addPila();
					break;
				case 3:
					addEntre();
					break;
				case 4:
					borrarCabeza();
					break;
				case 5:
					borrarCola();
					break;
				case 6:
					borrarEntre();
					break;
				case 7:
					Kumiko.BorrarLista();
					break;
				case 8:
					verLista();
					break;
				case 9:
					cout << endl << "Hay " << Kumiko.nElementos() <<
					(Kumiko.nElementos() == 1 ? " elemento" : " elementos ") << " en la lista." << endl;
					pausa();
					break;
				case 10:
					limpiar();
					r = 'N';
					break;
				default:
					limpiar();
					break;
			}
		}
		void loop(){
			while(r != 'N'){
				menu();
			}
		}
};

#endif
