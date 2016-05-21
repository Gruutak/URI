#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	int codigo, n1, n2;
	double valor1, valor2;

	cin >> codigo >> n1 >> valor1;
	cin >> codigo >> n2 >> valor2;

	cout << fixed << setprecision(2) << "VALOR A PAGAR: R$ " << (n1*valor1) + (n2*valor2) << endl;

	return 0;
}