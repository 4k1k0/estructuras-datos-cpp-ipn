/*
	Vean la diferencia entre:
	  Clave: pescado
	  Mensaje: mejor me hubiera muerto
	  
	  Clave: pescado
	  Mensaje: mejor me hubiera muerto de chiquito
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class programa{
	private:
		int repeticiones = 0;
		int contCifrado;
		int contador;
		int filas, columnas;
		
		char llave[10];
		char llaveDesorden[10];
		char mensaje[100];
	public:
		void pedirClave();
		void pedirMensaje();
		void crearMatriz();
		void cifrar();
		void descifrar();
		void limpiar();
		void loop();
};

main(){
	programa chitoge;
	chitoge.loop();
}

void programa::pedirClave(){
	limpiar();
	cout << "Ingresa una clave:" << endl << " \257 ";
	cin >> llave;
}
void programa::pedirMensaje(){
	cout << "Ingresa un mensaje:" << endl << " \257 ";
	cin.ignore(strlen(llave), '\n');
	//cin.get(mensaje, 100);	
	cin.getline(mensaje, 100, '\n');
}
void programa::crearMatriz(){
	
	contador = contCifrado = 0;
	
	for(int i = 0; i < strlen(mensaje); i++){
		if(mensaje[i] != ' '){
			contador++;
		}
	}
	
	char noEspacios[contador];
	
	for(int i = 0; i < strlen(mensaje); i++){
		if(mensaje[i] != ' '){
			noEspacios[contCifrado] = mensaje[i];
			contCifrado++;
		}
	}
	cout << endl << endl << noEspacios << " tiene " << strlen(noEspacios) << " caracteres." << endl;
	
	filas = contador;
	columnas = strlen(llave);
	
	cout << filas << " letras distribuidas en  " << columnas << " columnas" << endl;
	
	((filas % columnas) != 0) ? filas = (filas / columnas) + 1 : filas = filas / columnas;
	
	cout << "Lo que nos genera una matriz[" << filas << "][" << columnas << "]" << endl;
	
	char cifrado[filas][columnas];
	
	contador = 0;
	for(int i = 0; i < filas; i++){
		for(int o = 0; o < columnas; o++){
			cifrado[i][o] = 'X';
			contador++;
		}
	}
	
	contador = 0;
	for(int i = 0; i < filas; i++){
		for(int o = 0; o < columnas; o++){
			if(noEspacios[contador] != NULL){
				cifrado[i][o] = noEspacios[contador];
				contador++;
			}
		}
	}
	
	
	
	
	cout << endl << endl << endl << "####################################################" << endl;
	
	cout << "\t";
	for(int i = 0; i < strlen(llave); i++){
		cout << "[" << llave[i] << "]";
	}
	cout << endl << endl;
	for(int i = 0; i < filas; i++){
		cout << "\t";
		for(int o = 0; o < columnas; o++){
			cout << "[" << cifrado[i][o] << "]";
		}
		cout << endl;
	}
	
	
}
void programa::cifrar(){	
	for(int i = 0; i < strlen(llave); i++){
		llaveDesorden[i] = llave[i];
	}
	cout << llaveDesorden << endl;
	{
		char c[1];
		for(int i = 1; i < strlen(llave); i++){
			for(int o = 0; o < (strlen(llave) -1); o++){
				if(llaveDesorden[o + 1] < llaveDesorden[o]){
					c[0] = llaveDesorden[o];
					llaveDesorden[o]  = llaveDesorden[o + 1];
					llaveDesorden[o + 1] = c[0];
				}	
			}
		}
	}
	
	cout << llaveDesorden << endl;
	
	int orden[10];
	contador = 0;
	for(int i = 0; i < strlen(llave); i++){
		for(int o = 0; o < strlen(llave); o++){
			if(llaveDesorden[i] == llave[o]){
				orden[i] = o;
				i++;
				o = 0;		
			}
		}
	}
	
	cout << endl << endl;
	for(int i = 0; i < strlen(llave); i++){
		cout << orden[i] << " ";
	}
	
}
void programa::descifrar(){
	
	//
	
}
void programa::limpiar(){
	#ifdef _WIN32
		system("cls");
	#else
		system ("clear");
	#endif
}
void programa::loop(){
	char r = 'S';
	while(r != 'N'){
		pedirClave();
		pedirMensaje();
		crearMatriz();
		cifrar();
		descifrar();
		// <--------
		r = ' ';
		while(r != 'S' && r != 'N'){
			cout << endl << "Repetir S/N  ";
			cin >> r;
			r = toupper(r);
		}
	}
}
