package com.algorithm;

import java.util.LinkedList;
import java.util.Queue;

public class BFS {
    public static boolean[] visited = new boolean[9];
    static int[][] graph = {{}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7}};

    public static void bfs(int start) {
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.offer(start);

        visited[start] = true;
        while(!queue.isEmpty()) {
            int v = queue.poll();
            System.out.print(v + " ");

            for (int node : graph[v]) {
                if (!visited[node]) {
                    queue.offer(node);
                    visited[node] = true; 
                }
            }
        }
    }

    public static void main(String[] args) {
        bfs(1);
    }
}
