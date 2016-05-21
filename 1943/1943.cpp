#include <iostream>

using namespace std;

int main(){
	int posicoes[] = { 1, 3, 5, 10, 25, 50, 100};
	string nomes[] = { "Top 1", "Top 3", "Top 5", "Top 10", "Top 25", "Top 50", "Top 100" };
	int posicao, i;

	cin >> posicao;

	for(i = 0; i < 7; i++){
		if(posicao <= posicoes[i]){
			cout << nomes[i] << endl;
			return 0;
		}
	}

	return 0;
}
