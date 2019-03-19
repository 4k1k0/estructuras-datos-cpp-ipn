#include<iostream>
using namespace std;

void Ordenar(int a[], int n);

int main(){

	system("clear");

	int Numeros[9] = {88, 2, 99, 22, 1, 299, 32, 5, 2323 };
	int T = 9;

	cout << "Arreglo original:" << endl;
	for(int i = 0; i < T; i++)
		cout << Numeros[i] << " ";
	cout << endl;

	Ordenar(Numeros, T);

	cout << "Arreglo ordenado:" << endl;
	for(int i = 0; i < T; i++)
		cout << Numeros[i] << " ";
	cout << endl;

	return 0;
}

void Ordenar(int a[], int n){
	int intervalo, i, j, k;

	intervalo = n / 2;

	while(intervalo > 0){
		for(i = intervalo; i < n; i++){
			j = i - intervalo;
			while(j >= 0){
				k = j + intervalo;
				if(a[j] <= a[k])
					j = -1;
				else{
					int temp;
					temp = a[j];
					a[j] = a[k];
					a[k] = temp;
					j -= intervalo;
				}
			}
		}
		intervalo = intervalo / 2;
	}
}
