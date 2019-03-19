/*HUFFMAN MAS O MENOS BUENO*/
#include <iostream>
#include <windows.h>
#include <string.h>
#include <queue>
#include <map>
#include <climits> //para obtener los bits de un CHAR
#include <iterator>
#include <algorithm>
#include <sstream> // para stringstream

using namespace std;

const int SimbolosEspeciales = 1 << CHAR_BIT;
const char* EnunciadoPrueba = "MISSISSIPPI RIVER"; //Enunciado para probar

typedef vector<bool> CodigoHuffman;
typedef map<char, CodigoHuffman> CodigoHuffmanMap;

//Clase nodo, para iniciar, junto con destructor
class I_Nodo
{
	public:
		const int f;
		virtual ~I_Nodo() {}
		
	protected:
		I_Nodo(int f) : f(f) {}
};

//Nodo para realizar los subarboles, los hijos izquieros y derechos
class NodoInterno : public I_Nodo
{
	public:
		I_Nodo *const izq;
		I_Nodo *const der;
		
		NodoInterno(I_Nodo* c0, I_Nodo* c1) : I_Nodo(c0->f + c1->f), izq(c0), der(c1) {}
		~NodoInterno()
		{
			delete izq;
			delete der;
		}
};

//Clase para los nodos hoja
class NodoHoja : public I_Nodo
{
	public:
		const char c;
		NodoHoja(int f, char c) : I_Nodo(f), c(c) {}
};

//Factor Equilibrante para la comparacion de los niveles, mediante desplazamientos booleanos
struct NodoComparacion
{
	bool operator()(const I_Nodo* lhs, const I_Nodo* rhs) const{ return lhs->f > rhs->f; }
};

/*La libreria map y iterator que me permite reducir el codigo del arbol PERO
require de palabras clave especificas como size, end, begin y priority, ya que
vienen por defecto en la funcion de la libreria*/
I_Nodo* Arbol(const int (&frecuencia)[SimbolosEspeciales])
{
	priority_queue <I_Nodo*, vector <I_Nodo*>, NodoComparacion> arboles;
	
	for(int i=0; i<SimbolosEspeciales; ++i)
	{
		if(frecuencia[i] != 0)
		{
			arboles.push(new NodoHoja(frecuencia[i], (char)i));
		}
	}
	
	while(arboles.size() > 1)
	{
		I_Nodo* HijoD = arboles.top();
		arboles.pop();
		
		I_Nodo* HijoI = arboles.top();
		arboles.pop();
		
		I_Nodo* rama = new NodoInterno(HijoD, HijoI);
		arboles.push(rama);
	}
	return arboles.top();
}

//Transforma las letras de la cadena a binarios, realizando los prefijos tambien
//Utilizando dinamico


void GenerarBinarios(const I_Nodo* nodo, const CodigoHuffman& prefijo, CodigoHuffmanMap& salidas)
{
	if(const NodoHoja* nh = dynamic_cast<const NodoHoja*>(nodo))
	{
		salidas[nh->c] = prefijo;
	}
	
	else if(const NodoInterno* ni = dynamic_cast<const NodoInterno*>(nodo))
	{
		CodigoHuffman prefijo_izq = prefijo;
		prefijo_izq.push_back(false);
		GenerarBinarios(ni->izq, prefijo_izq, salidas);
		
		CodigoHuffman prefijo_der = prefijo;
		prefijo_der.push_back(true);
		GenerarBinarios(ni->der, prefijo_der, salidas);
	}
}

int main()
{
	system("color 0E");
	SetConsoleTitle("Codigo de Huffman mas o menos Bueno, no le prometo nada maestra");
	
	//Mostrar lo tabla de frecuencia de las letras
	int frecuencia[SimbolosEspeciales]={0};
	const char* ptr = EnunciadoPrueba;
	while(*ptr != '\0')
	{
		++frecuencia[*ptr++];
	}
	
	I_Nodo* raiz = Arbol(frecuencia);
	
	CodigoHuffmanMap Bin; //Objeto Bin 
	GenerarBinarios(raiz, CodigoHuffman(), Bin);
	delete raiz;
	
	//---------------Imprimir la frase original y los valores binarios de cada letra
	cout << "Texto Original \257 " << EnunciadoPrueba << endl
 		 << "Numero de caracteres del texto \257 " << strlen(EnunciadoPrueba) << endl
 		 << "Total de Bits del Texto Original '8 x " << strlen(EnunciadoPrueba) << "' = " << (8*strlen(EnunciadoPrueba)) << " bits.\n" << endl
 		 << "PESO BINARIO DE CADA LETRA\n";
 		 
 	// Imprimir los valores binarios
 	
 	/*
 	 *  Letras para guardar las letras
 	 *  Numeros para guardar los números.
	 */
	vector<char> Letras;
 	vector<string> Numero;
 	
	for(CodigoHuffmanMap::const_iterator it = Bin.begin(); it != Bin.end(); ++it)
	{
		// Imprimir y guardar la letra
		cout << it->first << " = ";
		Letras.push_back(it->first);
		
		//Imprimir el número
		copy(it->second.begin(), it->second.end(), ostream_iterator<bool>(cout));
		cout << endl;
		
		// Guardar el número
		string secuencia;
		for( bool val : it->second)
      	secuencia.append(std::to_string(val));
    	Numero.push_back(secuencia);
		
	}
	
	//---------------Imprimir la compresion del texto---
	cout << "\nMensaje:\n"
		 << EnunciadoPrueba << endl;
	
	cout << "Comprension" << endl;
	for(int i = 0; i < strlen(EnunciadoPrueba); i++){
		for(int j = 0; j < Letras.size(); j++){
			if(Letras[j] == EnunciadoPrueba[i]){
				// Comprueba que está en orden imprimiendo Letras[j]
				// en lugar de Numero[j]
				cout << Numero[j] << "_";
				continue;
			}
		}
	}
	
	
		 
	cout << "\nTotal = " ;
	return 0;
}
