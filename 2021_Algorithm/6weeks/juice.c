#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int n, m;
int graph[1000][1000];

bool dfs(int x, int y) {
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}
	if (graph[x][y] == 0) {
		graph[x][y] = 1;
		dfs(x - 1, y); 
		dfs(x + 1, y); 
		dfs(x, y - 1); 
		dfs(x, y + 1); 
		return true;
	}
	return false;
}

void main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) {
				result += 1;
			}
		}
	}

	printf("%d\n", result);
}
