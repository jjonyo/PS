/*
    2022.04.28
    BOJ : 2307 도로검문 (https://www.acmicpc.net/problem/2307)
    Algorithm : 다익스트라
*/

import java.util.*;
import java.io.*;

public class BOJ2307 {

    static int N, M;
    static ArrayList<Pair>[] adj;
    static int[] parent;
    static int[] dist;
    static PriorityQueue<Pair> pq = new PriorityQueue<>();

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        adj = new ArrayList[N + 1];
        dist = new int[N + 1];
        parent = new int[N + 1];

        parent[1] = 1;

        for (int i=1; i<=N; i++) adj[i] = new ArrayList<>();

        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            adj[a].add(new Pair(b, d));
            adj[b].add(new Pair(a, d));
        }
    }

    public static int dijkstra(boolean isFirst) {
        for (int i=1; i<=N; i++) dist[i] = Integer.MAX_VALUE;

        pq.clear();

        dist[1] = 0; 
        
        pq.add(new Pair(1, 0));

        while (!pq.isEmpty()) {
            Pair cur = pq.poll();

            if (dist[cur.n] < cur.dist) continue;

            for (Pair next : adj[cur.n]) {
                if (!next.isAble) continue;
                int nextDist = cur.dist + next.dist;

                if (dist[next.n] > nextDist) {
                        if (isFirst)
                            parent[next.n] = cur.n;
                        dist[next.n] = nextDist;
                        pq.add(new Pair(next.n, nextDist));
                    }
                }
            }
            
            return dist[N];
        }
        
        
    public static void main(String[] args) throws IOException {
        input();
            
        int max = 0;
        int min = dijkstra(true);
        
        int cur = N;
        while(cur != parent[cur]) {
            int prev = parent[cur];
            
            for (Pair next : adj[prev]) {
                if (next.n == cur) {
                    next.isAble = false;
                    int ret = dijkstra(false);
                    if (ret == Integer.MAX_VALUE) {
                        System.out.println(-1);
                        return;
                    } 
                    max = Math.max(max, ret);
                    next.isAble = true;
                    break;
                }
            }

            cur = parent[cur];
        }

        if (max > min) {
            System.out.println(max - min);
        }
    }


    public static class Pair implements Comparable<Pair> {
        
        int n, dist;
        boolean isAble = true;

        public Pair(int n, int dist) {
            this.n = n;
            this.dist = dist;
        }

        @Override
        public int compareTo(Pair p) {
            return this.dist - p.dist;
        }

    }
}