#include<iostream>
using namespace std;
#include "akko.h"

class Pila{
public:
    Pila(): MAX{0}, elementos{0} {} // Un constructor por si el objeto se crea sin inicializar.
    Pila(int n): MAX{n} {
        /*
         * En el constructor se inicializan los valores
         * contenidos en el arreglo y se inicializan
         * la variable elementos y la variable MAX;
         * esta última se utiliza para declarar el número
         * de elementos del arreglo
         * int* numero = new int[MAX]
         */
        for(int i = 0; i < MAX; ++i)
            numeros[i] = 0;
        elementos = 0;
    }
    ~Pila(){
        /*
         * El destructor del objeto también liberará
         * la memoria ocupada por el arreglo
         * int* numeros = new int[MAX]
         * con la instrucción
         * delete[]    ---> Aquí se utiliza el []
         * porque lo que se va a eliminar es un arreglo.
         */
        delete[] numeros;
    }
    int tamano() const{
        /*
         * Se le agrega la palabra const
         * a la función porque ésta no
         * sobreescribe ningún elemento de la clase,
         * es decir, es una función de Sólo Lectura.
         */
        return elementos;
    }
    void meter(int n){
        if(elementos < MAX){
            numeros[elementos] = n;
            ++elementos;
        }
    }
    void sacar(){
        if(elementos > MIN)
            --elementos;
    }
    void imprimir(){
        for(int i = 0; i < elementos; ++i)
            cout << i + 1 << ") " << numeros[i] << endl;
    }
    
    Pila& operator=(const Pila& a){
        /*
         * Esto nos sirve para copiar objetos de tipo Pila.
         * E.g. pilaA = pilaB;
         * Donde todos los datos de pilaA son reemplazados
         * por los datos de pilaB
         */
        MAX = a.MAX;
        elementos = a.elementos;
        delete[] numeros;
        numeros = a.numeros;
    }
    
private:
    int elementos;
    int MAX;
    const int MIN = 0;
    int* numeros = new int[MAX];
    /*
     * Estos son los arreglos de C++ ( int numeros[n]; en el lenguaje C )
     * Ya que al declararlos de esta manera se pueden destruir
     * y liberar la memoria que ocupan.
     * 
     * TipoDeDato* Nombre = new TipoDeDato[Número de elementos];
     */
};


int main(){
    Akko::nombrePantalla("Emular Pilas");
    Akko::limpiarPantalla();
    
    /*
     * El crear los objetos de esta manera
     * Clase* nombre = new Clase{Inicializar el objeto};
     * permite liberar la memoria ocupada por el objeto
     * y sus datos con la instrucción
     * delete objeto;
     * 
     * Si el objeto no se inicializa (pilaC) se utiliza
     * el constructor que pone todas las variables en 0
     */
    
    Pila* pilaA = new Pila{3};
    Pila* pilaB = new Pila{6};
    Pila* pilaC = new Pila;
    
    /*
     * Las funciones de estos objetos se ejecutan
     * objeto->funcion()
     */
    
    for(int i = 0; i < 20; ++i){
        pilaA->meter(i + 1);
        pilaB->meter(i + 1);
        pilaC->meter(i + 1);
    }
    
    cout << "*pilaA tiene un tamanio de " << pilaA->tamano() << endl;
    pilaA->imprimir();
    cout << "*pilaB tiene un tamanio de " << pilaB->tamano() << endl;
    pilaB->imprimir();
    cout << "*pilaC tiene un tamanio de " << pilaC->tamano() << endl;
    pilaC->imprimir();
    
    pilaC = pilaA;
    cout << "*pilaC tiene un tamanio de " << pilaC->tamano() << endl;
    pilaC->imprimir();
    
    for(int i = 0; i < 5; ++i){
        pilaA->sacar();
        pilaB->sacar();
        pilaC->sacar();
    }
    
    cout << "*pilaA tiene un tamanio de " << pilaA->tamano() << endl;
    pilaA->imprimir();
    cout << "*pilaB tiene un tamanio de " << pilaB->tamano() << endl;
    pilaB->imprimir();
    cout << "*pilaC tiene un tamanio de " << pilaC->tamano() << endl;
    pilaC->imprimir();
    
    pilaA->meter(666);
    cout << "*pilaA tiene un tamanio de " << pilaA->tamano() << endl;
    pilaA->imprimir();
    pilaC = pilaA;
    cout << "*pilaC tiene un tamanio de " << pilaC->tamano() << endl;
    pilaC->imprimir();
    
    pilaB->meter(1999);
    cout << "*pilaB tiene un tamanio de " << pilaB->tamano() << endl;
    pilaB->imprimir();
    pilaC = pilaB;
    cout << "*pilaC tiene un tamanio de " << pilaC->tamano() << endl;
    pilaC->imprimir();
    
     /*
     *  pp son en realidad 3 objetos de Pila, y cada uno es inicializado con
     *  2, 3, 0 respectivamente (El 0 se pone con el constructor)
     *  
     *  Clase* nombre = new Clase[número de objetos]{Inicializar los objetos};
     * 
     *  Las funciones de estos objetos se ejecutan
     *  objeto[n].funcion()
     *  
     */
    
    Pila* pp = new Pila[3]{2, 3};
    
    for(int i = 0; i < 100; ++i){
        pp[0].meter(i + 1);
        pp[1].meter(i + 1);
        pp[2].meter(i + 1);
    }
    
    cout << "***pp[0]*** tiene un tamanio de " << pp[0].tamano() << endl;
    pp[0].imprimir();
    cout << "***pp[1]*** tiene un tamanio de " << pp[1].tamano() << endl;
    pp[1].imprimir();
    cout << "***pp[2]*** tiene un tamanio de " << pp[2].tamano() << endl;
    pp[2].imprimir();
    
    delete[] pp;
    
    Akko::pausa("");
    
    
    
    return 0;
}
