#include<iostream>
#include<fstream>
using namespace std;

class Loop{
	private:
		ofstream Impar;
		ofstream Par;
	public:
		void abrir(){
			int impares[5] = {1, 5, 15, 25, 33};
			int pares[7] = {6, 8, 10, 12, 50, 60, 70};
			
			Impar.open("impar.txt");
			Par.open("par.txt");
			
			/* Impar */
			for(int i = 0; i < 5; i++)
				Impar << impares[i] << endl;
			/* Par */
			for(int i = 0; i < 7; i++)
				Par << pares[i] << endl;
				
			/* Cerrar los archivos */
			Impar.close();
			Par.close();
			
			/* Mensaje */
			cout << "Se crearon los archivos impar.txt y par.txt" << endl <<
			endl << "Impar.txt:" << endl;
			for(int i = 0; i < 5; i++)
				cout << impares[i] << " ";
			cout <<
			endl << "Par.txt" << endl;
			for(int i = 0; i < 7; i++)
				cout << pares[i] << " ";
			cout << endl;
			
			
			cin.ignore().get();
		}
};

int main(){
	Loop l;
	l.abrir();
	return 0;
}
