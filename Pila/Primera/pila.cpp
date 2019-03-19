#include<iostream>
using namespace std;

class programa{
	private:
		char r = 'S';
		int contador = 0;
		int numeros[5];
		int n;
	public:
		programa(){
			for(int i = 0; i < 5; i++)
				numeros[i] = 0;
		}
		void push();
		void pop();
		void mostrar();
		void menu();
		void loop();
};

int main(){
	programa wendy;
	wendy.loop();
	return 0;
}

void programa::push(){
	system("cls");
	if(contador < 5){
		cout << "Ingresa un numero para la pila: ";
		cin >> n;
		numeros[contador] = n;
		contador++;
	}
	else{
		cout << "La pila esta llena" << endl;
		system("pause");
	}
}

void programa::pop(){
	system("cls");
	if(contador > 0 && contador <= 5){
		numeros[contador -1] = 0;
		contador--;
		cout << "Se quito un numero a la pila" << endl;
		system("pause");
	}
	else{
		cout << "La pila esta vacia. " << endl;
		system("pause");
	}
}

void programa::mostrar(){
	system("cls");
	cout << "Los datos de la pila son: " << endl;
	for(int i = 0; i < 5; i++)
		cout << i + 1 << ")\t" << numeros[i] << endl;
	system("pause");
}

void programa::menu(){
	system("cls");
	cout << "1) Ingresar numero" <<
	endl << "2) Quitar numero" <<
	endl << "3) Mostrar pila" <<
	endl << "4) Salir" <<
	endl << "\256 ";
	int m;
	cin >> m;
	
	switch(m){
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			mostrar();
			break;
		case 4:
			r = 'N';
			break;
		default:
			system("cls");
			break;
	}
}

void programa::loop(){
	while(r != 'N'){
		menu();
	}
}
