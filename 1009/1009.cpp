#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>

using namespace std;

int main(){

	string nome;
	double salario, vendas;

	cin >> nome >> salario >> vendas;

	printf("TOTAL = R$ %.2f\n", salario + vendas*0.15);

	return 0;
}