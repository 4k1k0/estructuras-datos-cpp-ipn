#ifndef LOOP_H
#define LOOP_H


#include "arbol.h"

class Loop{
	private:
		char r = 'S';
		char menuOp;
		int n, h;
		Arbol Kyou;   /* Se crea un bojeto derivado de la clase Árbol */
	public:
		void ingresar();
		void mostrar();
		void buscar();
		void limpiar();
		void pausa();
		void esperar(float segundos);
		void menu();
		void loop();
};


#endif
