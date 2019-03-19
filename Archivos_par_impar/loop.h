#ifndef LOOP_H
#define LOOP_H

#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<sstream>

class Loop{
	private:
		vector<int> Numeros;
		string linea;
		int numero;
		ifstream Impar;
		ifstream Par;
	public:
		void abrirArchivos(){
			cout << "Abriendo archivo par.txt..." <<
			endl << "Abriendo archivo impar.txt..." << endl;
			
			Impar.open("impar.txt");
			Par.open("par.txt");
			
			if(Impar.fail() || Par.fail()){
				limpiar();
				cout << "Error al abrir los archivos." <<
				endl << "Compruebe que el archivo existe." << endl;
				exit(1);
			}			
			
			leerImpar();
			leerPar();
			imprimir();
			crearArchivo();
			
			Numeros.clear();
			
		}
		void leerImpar(){
			while(getline(Impar, linea)){
				istringstream iss(linea);
				if(iss >> numero)
					Numeros.push_back(numero);
			}
			cout << endl << "Impar.txt" << endl;
			for(int i = 0; i < Numeros.size(); i++)
				cout << Numeros[i] << " ";
		}
		void leerPar(){
			int i = Numeros.size();
			while(getline(Par, linea)){
				istringstream iss(linea);
				if(iss >> numero)
					Numeros.push_back(numero);
			}
			cout << endl << "Par.txt" << endl;
			for(i = i; i < Numeros.size(); i++)
				cout << Numeros[i] << " ";
		}
		void ordenar(){
			/* Se ordenan con el algoritmo de méto de inserción */
			int temporal;
			for(int i = 1; i < Numeros.size(); i++){
				temporal = Numeros[i];
				int j = i - 1;
				while((Numeros[j] > temporal) && j >= 0){
					Numeros[j + 1] = Numeros[j];
					j--;
				}
				Numeros[j + 1] = temporal;
			}
		}
		void imprimir(){
			cout << endl << "Combinacion de archivos" << endl;
			for(int i = 0; i < Numeros.size(); i++)
				cout << Numeros[i] << " ";
				
			cout << endl << "Ordenamiento por seleccion" << endl;
			ordenar();
			for(int i = 0; i < Numeros.size(); i++)
				cout << Numeros[i] << " ";
		}
		void crearArchivo(){
			cout << endl << "Creando archivo numeros.txt" << endl;
			ofstream Numeros_Salida;
			Numeros_Salida.open("numeros.txt");
			
			for(int i = 0; i < Numeros.size(); i++)
				Numeros_Salida << Numeros[i] << endl;
			
			cout << "Archivo creado con exito." << endl;
			
			Numeros_Salida.close();
		}
		void limpiar(){
			#ifdef _WIN32
				system("cls");
			#else
				system("clear");
			#endif
		}
};

#endif
