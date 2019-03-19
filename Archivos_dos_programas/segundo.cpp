#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

class Loop{
	private:
		ifstream Impar;
		ifstream Par;
		ofstream Numeros;
	public:
		void leer(){
			
			
			/* Abrir los archivos impar.txt y par.txt */
			Impar.open("impar.txt");
			Par.open("par.txt");
			if(Impar.fail() || Par.fail()){
				cout << "Error al abrir los archivos." << endl;
				cin.ignore().get();
				exit(1);
			}
			
			/* Intercalar */
			Numeros.open("numeros.txt");
			
			// Variables para almacenar los números
			// y así poder compararlos.
			int a, b;
			Impar >> a;
			Par >> b;
						
			// Mientras los archivos llegan al final
			while(!Impar.eof() || !Par.eof()){
				// a -> Impar
				// b -> Par
				
				// Los uno de los archivos aún no llegan al final
				if(!Impar.eof() && !Par.eof()){
					if(a < b){
						Numeros << a << endl;
						Impar >> a;
					}
					else if(a > b){
						Numeros << b << endl;
						Par >> b;
					}
				}
				
				// Impar aún no llega al final
				else if(!Impar.eof() && Par.eof()){
					Numeros << a << endl;
					Impar >> a;
				}
				// Par aún no llega al final
				else if(!Par.eof() && Impar.eof()){
					Numeros << b << endl;
					Par >> b;
				}
			}
			
			
			Numeros.close();
			
		}
};

int main(){
	Loop l;
	l.leer();
	return 0;
}
