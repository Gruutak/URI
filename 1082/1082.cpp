#include <cstdio>
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

void BFS(int graph[MAXN][MAXN], int raiz, int N) {
    int i;
	queue<int> fila;
	int atual;

	cor[raiz] = CINZA;

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
	int cont = 0;
	list<int>::iterator it;

	scanf("%d", &C);

	for (k=0; k < C;k++){
		scanf("%d %d", &N, &M);

		for (i=0; i < N; i++)
			for (j=0; j < N; j++)
				graph[i][j] = 0;

		for (i=0; i < M; i++){
			scanf(" %c", &x);
	        scanf(" %c", &y);
			u = x - 'a';
			v = y - 'a';
			graph[u][v] = graph[v][u] = 1;
		}

		for (i = 0; i < N; i++) cor[i] = BRANCO;

		cont = 0;
		printf("Case #%d:\n", k+1);
		for(i = 0; i < N; i++) {
			if(cor[i] == BRANCO) {
				componente.clear();
				cont++;
				BFS(graph, i, N);

				componente.sort();

				for (it = componente.begin(); it != componente.end(); ++it)
	    			printf("%c,", *it + 'a');
				printf("\n");
			}
		}
		printf("%d connected components\n\n", cont);
	}
}
