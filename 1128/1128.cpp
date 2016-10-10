#include <cstdio>

#define MAXN 2000

int color[MAXN];
int graph[MAXN][MAXN];

void DFS(int N, int v) {
	int i;

	color[v] = 1;

	for(i = 0; i < N; i++)
		if(graph[v][i])
			if(color[i] == -1)
				DFS(N, i);

	return;
}


int main(){
	int N, M;
	int V, W, P;
	int i, j;
	int flag;

	while(1) {
		scanf("%d %d", &N, &M);

		if(N == 0 && M == 0)
			break;

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				graph[i][j] = 0;

		for (i = 0; i < M; i++) {
			scanf("%d %d %d", &V, &W, &P);

			if (P == 2)
				graph[W-1][V-1] = 1;
			graph[V-1][W-1] = 1;
		}

		//debug
		/*
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++)
				printf("%d ", graph[i][j]);
			printf("\n");
		}*/

		for (i = 0; i < N; i++) {
			flag = 1;

			for (j = 0; j < N; j++)
				color[j] = -1;

			DFS(N, i);

			for (j = 0; j < N; j++) {
				if (color[j] == -1) {
					flag = 0;
					break;
				}
			}

			if(!flag) {
				break;
			}

		}
		printf("%d\n", flag);

	}

	return 0;
}
