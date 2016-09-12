#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAXN 123

int color[MAXN];
bool ret;

void DFS(int graph[MAXN][MAXN], int N, int v) {
	int i;

	for(i = 0; i < N; i++) {
		if(graph[v][i]) {
			if(color[i] == -1) {
				color[i] = !color[v];
				DFS(graph, N, i);
			}
			else if(color[i] == color[v] && i != v) {
				ret = false;
			}
		}
	}

	return;
}

int main(int argc, char** argv) {
	char x,y;
	int N, M, C, i, j, k, u, v;
	int graph[MAXN][MAXN];
	char string[500];
	char * token;


	/*Reads number vertices */
	fgets(string, sizeof(string), stdin);
	sscanf(string, "%d", &N);

	while(N != 0){
		/* Initialize graph matrix */
		for (i=0; i < N; i++)
			for (j=0; j < N; j++)
				graph[i][j] = 0;

		for (k=0; k < N; k++) {
			/* Reads vertex */
			fgets(string, sizeof(string), stdin);
			sscanf(string, "%d", &i);

			/* Reads list of vertices adjacent to vertex i */
			fgets(string, sizeof(string), stdin);
			token = strtok(string," ");
			while (token != NULL){
				j = atoi(token);
				graph[i-1][j-1] = 1;
				token = strtok(NULL," ");
			}
		}

		ret = true;

		for(i = 0; i < N; i++)
			color[i] = -1;

		for(i = 0; i < N; i++) {
			if(color[i] == -1) {
				color[i] = 1;
				DFS(graph, N, i);
			}
		}

		ret ? printf("SIM") : printf("NAO");
		printf("\n");

		/* Reads number of vertices. */
		fgets(string, sizeof(string), stdin);
		sscanf(string, "%d", &N);
	}

	return 0;
}
