#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
	int numero, horas;
	double valor, salario;

	cin >> numero >> horas >> valor;

	salario = valor * horas;

	cout << "NUMBER = " << numero << endl;
	printf("SALARY = U$ %.2f\n", salario);

	return 0;
}