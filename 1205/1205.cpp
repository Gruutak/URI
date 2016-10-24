#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

#define MAX 1000

int graph[MAX][MAX];
int Q[MAX];
int dist[MAX];

int DIJKSTRA(int M, int src) {
	int u, i, qtQ = M;

	for(i = 0; i < M; i++)
		dist[i] = 2001;

	dist[src] = graph[src][src];


	while(qtQ > 0) {
		for(i = 0, u = 0; i < M; i++) {
			if(Q[i] == 1 && dist[i] <= dist[u]) {
				u = i;
			}
		}
		Q[u] = 0;
		qtQ--;

		for(i = 0; i < M; i++) {
			//printf("Comparando u: %d com i:%d, Q[%d]:%d... dist[u]:%d, dist[i]:%d, graph:%d\n", u, i, i, Q[i], dist[u], dist[i], graph[u][i]);
			if(Q[i] == 1 && i != u && (dist[i] > dist[u] + graph[u][i])) {
				dist[i] = dist[u] + graph[u][i];
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
	float P;

	while(cin >> N){
		scanf("%d %d %f", &M, &K, &P);

		// Init Graph
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++)
				graph[i][j] = 2001;
		}

		for (i = 0; i < N; i++) {
			graph[i][i] = 0;
			Q[i] = 1;
		}

		for (i = 0; i < M; i++) {
			scanf("%d %d", &pos1, &pos2);
			graph[pos1-1][pos2-1] = 0;
		}

		scanf("%d", &shooterAmount);

		for(i = 0; i < shooterAmount; i++) {
			scanf("%d", &shooterPos);

			if(graph[shooterPos-1][shooterPos-1] > 2000)
				graph[shooterPos-1][shooterPos-1] = 0;

			for(j = 0; j < N; j++)
				if(graph[j][shooterPos-1] < 2001) {
					graph[j][shooterPos-1]++;
				}

		}

		scanf("%d %d", &start, &end);


		if(K < shooterAmount) {
			printf("%.3f\n", 0.0);
			continue;
		}

		DIJKSTRA(N, start-1);

		printf("%.3f\n", pow(P, dist[end-1]));
	}

	return 0;
}
