#include<iostream>
using namespace std;

void Ordenar(int a[], int primero, int ultimo);

int main(){

	system("clear");
	
	int Numeros[10] = { 1, 299, 7, 44, 22, 56, 23, 71, 2, 289 };
	
	cout << "Arreglo orinal:" << endl;
	for(int i = 0; i < 10; i++)
		cout << Numeros[i] << " ";
	cout << endl;

	Ordenar(Numeros, 0, 10 - 1);

	cout << "Arreglo ordenado: " << endl;
	for(int i = 0; i < 10; i++)
		cout << Numeros[i] << " ";
	cout << endl;

	return 0;
}

void Ordenar(int a[], int primero, int ultimo){
	int central;
	int pivote;
	central = (primero + ultimo) / 2;
	pivote = a[central];

	int i = primero;
	int j = ultimo;

	do{
		while(a[i] < pivote) i++;
		while(a[j] > pivote) j--;
		if(i <= j){
			double temporal;
			temporal = a[i];
			a[i] = a[j];
			a[j] = temporal;
			i++;
			j--;
		}
	} while(i <= j);

	if(primero < j)
		Ordenar(a, primero, j);
	if(i < ultimo)
		Ordenar(a, i, ultimo);
}
