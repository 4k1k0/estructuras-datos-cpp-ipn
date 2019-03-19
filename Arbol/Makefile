#Crear ejecutable del programa de árbol(*nix).

# Esta regla compila el programa principal
# y elimina los archivos con extensión .o
# que se generan.

Arbol: main.o arbol.o loop.o
	g++ main.o arbol.o loop.o -o Arbol
	rm -r *.o

# Esta regla crea el archivo main.o
# utilizando el archivo main.cpp
# el cual manda a llamar a loop.h
# el cual manda a llamar a arbol,h
# el cual manda a llamar a nodo,h

main.o: main.cpp
	g++ -c main.cpp -std=c++14

arbol.o: arbol.cpp arbol.h
	g++ -c arbol.cpp -std=c++14

loop.o: loop.cpp loop.h
	g++ -c loop.cpp -std=c++14

# Es el parámetro clean que elimina el ejecutable Arbol.
clean:
	rm -r Arbol


