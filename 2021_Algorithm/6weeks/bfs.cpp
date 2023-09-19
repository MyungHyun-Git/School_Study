#include <bits/stdc++.h>

using namespace std;
bool visited[9];

int graph[9][3] = { {}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7} };

void bfs(int start) {
	queue<int> queue;
	queue.push(start);
	visited[start] = true;

	while (!queue.empty()) {
		int v = queue.front(); 
		queue.pop();
		cout << v << ' ';
		for (int node : graph[v]) { 
			if (!visited[node]) {
				queue.push(node);
				visited[node] = true;
			}
		}
	}
}

void main() {
	visited[0] = true; 
	bfs(1);
}
