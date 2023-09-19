def dfs(x, y):
    stack = []
    stack.append((x, y))

    while stack:
        x, y = stack.pop()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
           
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if graph[nx][ny] == 0:
                continue
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                stack.append((nx, ny))
            elif graph[nx][ny] > graph[x][y] + 1:
                graph[nx][ny] = graph[x][y] + 1
                stack.append((nx, ny))

    return graph[n - 1][m - 1]

n, m = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
print(dfs(0, 0))
