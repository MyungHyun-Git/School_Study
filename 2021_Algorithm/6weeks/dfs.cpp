#include <bits/stdc++.h>

using namespace std;
bool visited[9];

int graph[9][3] = { {}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7} };

void dfs(int v) {
	visited[v] = true;
	cout << v << ' ';

	for (int node : graph[v]) {
		if (!visited[node]) {
			dfs(node);
		}
	}
}

void main() {
	visited[0] = true;
	dfs(1);
}
