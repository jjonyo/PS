/*
    2022.05.03
    BOJ : 20182 골목 대장 호석-효율성1 (https://www.acmicpc.net/problem/20182)
    Algorithm : 다익스트라
*/

import java.util.*;
import java.io.*;

public class BOJ20182 {

    static int N,M,A,B,C;
    static ArrayList<Pair>[] adj;
    static int[][] dist;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        dist = new int[N + 1][21];
        adj = new ArrayList[N + 1];
        for (int i=1; i<=N; i++) adj[i] = new ArrayList<>();

        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            adj[a].add(new Pair(b, c));
            adj[b].add(new Pair(a, c));
        }
    }

    public static void dijkstra(int start, int maximum) {
        for (int i=1; i<=N; i++) dist[i][maximum] = Integer.MAX_VALUE;

        PriorityQueue<Pair> pq = new PriorityQueue<>();

        dist[start][maximum] = 0;

        pq.add(new Pair(start, 0));

        while (!pq.isEmpty()) {
            Pair cur = pq.poll();

            if (cur.n == B) break;
            if (dist[cur.n][maximum] < cur.dist) continue;

            for (Pair next : adj[cur.n]) {
                if (next.dist > maximum) continue;
                int nextDist = dist[cur.n][maximum] + next.dist;
                if (nextDist > dist[next.n][maximum]) continue;
                pq.add(new Pair(next.n, nextDist));
                dist[next.n][maximum] = nextDist;
            }
        }
    }
 
    public static void main(String[] args) throws IOException {
        input();


        for (int i=1; i<=20; i++) {
            dijkstra(A, i);
        }

        for (int i=1; i<=20; i++) {
            if (dist[B][i] <= C) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);
    }

    public static class Pair implements Comparable<Pair> {
        int n;
        int dist;

        public Pair(int to, int cost) {
            this.n = to;
            this.dist = cost;
        }

        public int compareTo(Pair p) {
            return this.dist - p.dist;
        }
    }
}