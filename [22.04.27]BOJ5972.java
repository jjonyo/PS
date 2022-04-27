/*
    2022.04.27
    BOJ : 5972 택배 배송 (https://www.acmicpc.net/problem/5972)
    Algorithm : 다익스트라
*/

import java.util.*;
import java.io.*;

public class BOJ5972 {

    static int N,M;
    static int[] dist;
    static ArrayList<Pair>[] adj;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        dist = new int[N + 1];
        adj = new ArrayList[N + 1];

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

    public static void dijkstra(int start) {
        PriorityQueue<Pair> PQ = new PriorityQueue<>();

        dist[start] = 0;
        PQ.add(new Pair(1, 0));

        while (!PQ.isEmpty()) {
            Pair cur = PQ.poll();

            if (dist[cur.num] < cur.dist) continue;

            for (Pair next : adj[cur.num]) {
                int nextDist = cur.dist + next.dist;
                if (dist[next.num] > nextDist) {
                    dist[next.num] = nextDist;
                    PQ.add(new Pair(next.num, nextDist));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        for (int i=1; i<=N; i++) dist[i] = Integer.MAX_VALUE;

        dijkstra(1);

        System.out.println(dist[N]);
    }

    public static class Pair implements Comparable<Pair> {
        int num;
        int dist;

        public Pair(int num, int dist) {
            this.num = num;
            this.dist = dist;
        }


        @Override
        public int compareTo(Pair p) {
            return this.dist - p.dist;
        }
    }
}