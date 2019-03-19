#ifndef NODO_H
#define NODO_H

/* 
 * La estructura de los nodos
 * El constructor inicializa 
 * los punteros derecha e izquierda.
 * */
class Nodo{
	private:
		int dato;
		Nodo* Derecha;
		Nodo* Izquierda;
	public:
		Nodo(int n): dato{n}, Derecha{nullptr}, Izquierda{nullptr} {}
		friend class Arbol;
};

#endif
