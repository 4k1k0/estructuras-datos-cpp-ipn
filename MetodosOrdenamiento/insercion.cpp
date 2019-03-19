#include<iostream>
using namespace std;

class seleccion{
	private:
		char r = 'S';
		int temporal, minimo;
		int numeros[5];
	public:
		void loop();
};

int main(){
	seleccion b;
	b.loop();
	return 0;
}

void seleccion::loop(){
	while(r != 'N'){
		system("cls");
		for(int i = 0; i < 5; i++){
			cout << i + 1 << ") Ingresa numero: ";
			cin >> numeros[i];
		}
		cout << "Arreglo original " << endl;
		for(int i = 0; i < 5; i++)
			cout << numeros[i] << "\t";
	
		for(int i = 1; i < 5; i++){
			temporal = numeros[i];
			int j = i - 1;
			while((numeros[j] > temporal) && j >= 0){
				numeros[j + 1] = numeros[j];
				j--;
			}
			numeros[j + 1] = temporal;
		}
		
		cout << endl << "Despues de la insercion... " << endl;
		for(int i = 0; i < 5; i++)
			cout << numeros[i] << "\t";
			
		cout << endl << "Presione Enter para continuar...";
		cin.ignore().get();
	}
}
