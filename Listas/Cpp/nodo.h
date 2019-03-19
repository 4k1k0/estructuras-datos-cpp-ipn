#ifndef NODO_H
#define NODO_H

class Nodo{
	private:
		int numero;
		Nodo* Siguiente;
	public:
		Nodo(int n): numero{n}, Siguiente{NULL} {}
		friend class Lista;
};

#endif
