package com.algorithm;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class MazeBFS {
  
    public static final int[] dx = { -1, 1, 0, 0};
    public static final int[] dy = { 0, 0, -1, 1};

    public static int n;
    public static int m;
    public static int[][] graph;
  
    public static int bfs(int x, int y) {
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(x, y));

        while(!queue.isEmpty()) {
            Node node = queue.poll(); 
            x = node.getX();
            y = node.getY();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (graph[nx][ny] == 0) continue;

                if (graph[nx][ny] == 1) {
                    graph[nx][ny] = graph[x][y] + 1;
                    queue.add(new Node(nx, ny));
                }
            }
        }
        return graph[n-1][m-1]; 
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
        System.out.println(bfs(0, 0));
    }

    static class Node{
        final private int x;
        final private int y;
        Node(int x, int y){
            this.x = x;
            this.y = y;
        }
        public int getX() { return x; }
        public int getY(){ return y; }
    }
}
