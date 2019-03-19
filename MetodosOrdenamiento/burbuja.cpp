#include<iostream>
using namespace std;

class burbuja{
	private:
		char r = 'S';
		int temporal;
		int numeros[5];
	public:
		void loop();
};

int main(){
	burbuja b;
	b.loop();
	return 0;
}

void burbuja::loop(){
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
			for(int j = 0; j < 5 - 1; j++){
				if(numeros[j] > numeros[j + 1]){
					temporal = numeros[j + 1];
					numeros[j + 1] = numeros[j];
					numeros[j] = temporal;
				}
			}
			
		}
		
		cout << endl << "Despues de la burbuja... " << endl;
		for(int i = 0; i < 5; i++)
			cout << numeros[i] << "\t";
			
		cout << endl << "Presione Enter para continuar...";
		cin.ignore().get();
	}
}
