#include <iostream>

using namespace std;

int main(){
	int i, j, n, custoPorDia, dias[50], lucro, temp;

	while(cin >> n){
		cin >> custoPorDia;

		for(i = 0; i < n; i++){
			cin >> dias[i];
		}

		lucro = dias[0] - custoPorDia;

		for(i = 0; i < n; i++){
			for(j = i, temp = 0; j < n; j++){
				temp += dias[j] - custoPorDia;
				if(temp > lucro)
					lucro = temp;
			}
		}

		if(lucro <= 0)
			cout << '0' << endl;
		else
			cout << lucro << endl;
	}

	return 0;

}
