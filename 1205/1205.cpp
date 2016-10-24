#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

#define MAX 1000

int graph[MAX][MAX];
int Q[MAX];
int dist[MAX];
int pred[MAX];
int shooters[MAX];

int DIJKSTRA(int N, int src) {
	int u, i, qtQ = N, min;

	for(i = 0; i < N; i++) {
		dist[i] = 2001;
		pred[i] = -1;
	}

	dist[src] = shooters[src];
	pred[src] = src;

	while(qtQ > 0) {
		for(i = 0, min = 2001; i < N; i++)
			if(Q[i] == 1 && dist[i] < min ) {
				u = i;
				min = dist[i];
			}

			//printf("u:%d\n", u);
		Q[u] = 0;
		qtQ--;
		for(i = 0; i < N; i++) {
			//printf("Comparando u: %d com i:%d, Q[%d]:%d... dist[u]:%d, dist[i]:%d, graph:%d\n", u, i, i, Q[i], dist[u], dist[i], graph[u][i]);
			if(Q[i] == 1 && graph[u][i] == 1 && (dist[i] > dist[u] + shooters[i])) {
				pred[i] = u;
				dist[i] = dist[u] + shooters[i];
				//printf("Mudando distancia de i(%d) para:%d\n", i, dist[i]);
			}
		}
	}

}

void printGraph(int M) {
	int i, j;

	printf("=============GRAPH=============\n");
	for(i = 0; i < M; i++){
		for(j = 0; j < M; j++)
			printf("\t%d", graph[i][j]);
		printf("\n");
	}
	printf("=============GRAPH=============\n\n");
}

int main(){
	int N, M, K;
	int pos1, pos2;
	int shooterPos, shooterAmount;
	int start, end;
	int i, j;
	double P;

	while(scanf("%d %d %d %lf", &N, &M, &K, &P) != EOF){
		// Init Graph
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++)
				graph[i][j] = 0;

			Q[i] = 1;
			shooters[i] = 0;
		}

		for (i = 0; i < M; i++) {
			scanf("%d %d", &pos1, &pos2);
			graph[pos1-1][pos2-1] = 1;
			graph[pos2-1][pos1-1] = 1;
		}

		scanf("%d", &shooterAmount);

		for(i = 0; i < shooterAmount; i++) {
			scanf("%d", &shooterPos);
			shooters[shooterPos-1]++;
		}

		scanf("%d %d", &start, &end);

		DIJKSTRA(N, start-1);
		//printf("dist: %d\n", dist[end-1]);
		printf("%.3lf\n", pow(P, dist[end-1]));
	}

	return 0;
}
