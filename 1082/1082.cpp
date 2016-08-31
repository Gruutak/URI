#include <iostream>
#include <queue>
#include <list>

using namespace std;

#define MAXN 30
#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define SWAP(a,b) { a^=b; b^=a; a^=b; }

int cor[MAXN];
list<int> componente;
int dist[MAXN], pred[MAXN];

void BFS(int graph[MAXN][MAXN], int raiz, int N) {
    int i;
	queue<int> fila;
	int atual;

	cor[raiz] = CINZA;
	dist[raiz] = 0;
	pred[raiz] = -1;

	fila.push(raiz);
	componente.push_back(raiz);

	while(!fila.empty()) {
		atual = fila.front();
		fila.pop();

		for (i = 0; i < N; i++) {
			if(i != atual) {
				if(graph[atual][i] > 0) {
					if(cor[i] == BRANCO) {
						cor[i] = CINZA;
						fila.push(i);
						componente.push_back(i);
						dist[i] = dist[atual]+1;
						pred[i] = atual;
					}
				}
			}
		}
		cor[atual] = PRETO;
	}

}

int main(int argc, char** argv) {
	char x,y;
	int N, M, C, i, j, k, u, v;
	int graph[MAXN][MAXN];
	int flag = -1, cont = 0;
	list<int>::iterator it;

	cin >> C;

	for (k=0; k < C;k++){
		cin >> N;
		cin >> M;

		for (i=0; i < N; i++)
			for (j=0; j < N; j++)
				graph[i][j] = 0;

		for (i=0; i < M; i++){
			cin >> x;
			cin >> y;
			u = x - 'a';
			v = y - 'a';
			graph[u][v] = graph[v][u] = 1;
		}

		for (i = 0; i < N; i++) {
			dist[i] = -1;
			pred[i] = -1;
			cor[i] = BRANCO;
		}

		cont = 0;
		cout << "Case #" << k+1 << ":" << endl;
		for(i = 0; i < N; i++) {
			if(cor[i] == BRANCO) {
				componente.clear();
				cont++;
				BFS(graph, i, N);

				componente.sort();

				for (it = componente.begin(); it != componente.end(); ++it)
	    			cout << (char)(*it + 'a') << ',';
				cout << endl;
			}
		}
		cout << cont << " connected components" << endl << endl;
	}
}
