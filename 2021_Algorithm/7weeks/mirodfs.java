package com.algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class MazeDFS {
    public static final int[] dx = {-1, 1, 0, 0};
    public static final int[] dy = {0, 0, -1, 1};

    public static int n;
    public static int m;
    public static int[][] graph;

    public static int dfs(int x, int y) {

        Stack<Node> stack = new Stack<Node>();
        Node node = new Node(x, y);
        stack.push(node);

        while (!stack.empty()) {
            node = stack.pop();
            x = node.getX();
            y = node.getY();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (graph[nx][ny] == 0) continue;

                if (graph[nx][ny] == 1) {
                    graph[nx][ny] = graph[x][y] + 1; 
                    stack.push(new Node(nx, ny)); 
                }
                else if (graph[nx][ny] > graph[x][y] + 1) {
                    graph[nx][ny] = graph[x][y] + 1;
                    stack.push(new Node(nx, ny));
                }
            }
        }

        return graph[n - 1][m - 1]; 
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        graph = new int[n][m];
        for (int i = 0; i < n; i++) {
            String mazeStr = br.readLine();
            for (int j = 0; j < m; j++) {
                graph[i][j] = mazeStr.charAt(j) - '0';
            }
        }
        br.close();
        System.out.println(dfs(0, 0));
    }

    static class Node {
        final private int x;
        final private int y;

        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }

}
