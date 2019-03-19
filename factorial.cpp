#include<iostream>
using namespace std;

int fIterativa(int n);
int fRecursiva(int n);

main(){
	int iterativa, recursiva;
	cout << "Factorial de manera Iterativa y Recursiva" << endl << endl;
	cout << "Ingresa un numero para la funcion Iterativa: ";
	cin >> iterativa;
	cout << "Ingresa un numero para la funcion Recursiva: ";
	cin >> recursiva;
	
	cout << endl << endl << endl;
	cout << "El factorial de " << iterativa << " usando la funcion Iterativa es " << fIterativa(iterativa) << endl;
	cout << "El factorial de " << recursiva << " usando la funcion Recursiva es " << fRecursiva(recursiva) << endl;
	
}

int fIterativa(int n){
	int f = 1;
	for(int i = 0; i < n; i++){
		f = f * (i + 1);
	}
	return f;
}
int fRecursiva(int n){
	if(n <= 1)
	    return 1;
	else
		return n * fRecursiva(n - 1);
}
