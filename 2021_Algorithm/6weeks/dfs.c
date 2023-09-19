#include <stdio.h>
#include <stdbool.h>
bool visited[9];
int graph[9][3] = { {NULL}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7} };

void dfs(int v) {
	visited[v] = true;
	printf("%d ", v);
	for (int i = 0; i < 3 && graph[v][i] != 0; i++) {
		if (!visited[graph[v][i]]) {
			dfs(graph[v][i]);
		}
	}
}

void main() {
	dfs(1);
}
