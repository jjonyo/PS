/*
    2022.04.26
    BOJ : 1240 노드사이의 거리 (https://www.acmicpc.net/problem/1240)
    Algorithm : BFS
*/

import java.util.*;
import java.io.*;

public class BOJ1240 {

    static int N, M;
    static ArrayList<Node>[] adj;
    static int[][] dist;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        

        adj = new ArrayList[N + 1];

        for (int i=1; i<=N; i++) {
            adj[i] = new ArrayList<Node>();
        }

        dist = new int[N+1][N+1];

        for (int i=0; i<N - 1; i++) {
            st = new StringTokenizer(br.readLine());

            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());

            adj[from].add(new Node(to, dist));
            adj[to].add(new Node(from, dist));
        }

        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            System.out.println(bfs(from, to));
        }
    }

    public static int bfs(int from, int to) {
        Queue<Node> Q = new LinkedList<>();
        boolean[] visit = new boolean[N + 1];
        Q.add(new Node(from, 0));
        visit[from] = true;

        while (!Q.isEmpty()) {
            Node cur = Q.poll();

            if (cur.to == to) {
                return cur.dist;
            }

            for (Node next : adj[cur.to]) {
                if (visit[next.to]) continue;
                visit[next.to] = true;
                Q.add(new Node(next.to, cur.dist + next.dist));                
            }
        }

        return 0;
    }

    public static void main(String[] args) throws IOException {
        input();
    }

    public static class Node {
        int to;
        int dist;

        public Node(int to, int dist) {
            this.to = to;
            this.dist = dist;
        } 
    }
}