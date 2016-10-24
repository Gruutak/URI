#include <stdio.h>

using namespace std;

#define MAX 60

int graph[MAX][MAX];


int PRIM(int R) {
	int W, i, j, u, Qsize = R-1;
	int Q[MAX];
	int menorPeso;

	W = 0;

	Q[0] = 0;

	for(i = 1; i < R; i++)
		Q[i] = 1;

	while(Qsize > 0) {
		Qsize--;

		menorPeso = 65535;
		for(i = 0; i < R; i++) {
			for (j = 0; j < R; j++) {
				if(graph[i][j] < menorPeso && Q[i] == 0 && Q[j] == 1) {
					menorPeso = graph[i][j];
					u = j;
				}
			}
		}

		Q[u] = 0;

		W += menorPeso;
	}

	return W;

}

int main(){
	int R, C, V, W, P;

	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
		for (int j = 0; j < R; j++)
			graph[i][j] = 65535;

	for (int i = 0; i < C; i++) {
		scanf("%d %d %d", &V, &W, &P);

		graph[V-1][W-1] = P;
		graph[W-1][V-1] = P;
	}

	printf("%d\n", PRIM(R));

	return 0;
}
