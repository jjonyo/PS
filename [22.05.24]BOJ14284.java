/*
    2022.05.24
    BOJ : 14284 간선 이어가기2 (https://www.acmicpc.net/problem/14284)
    Algorithm : 다익스트라
*/

import java.util.*;
import java.io.*;

public class BOJ14284 {

    static int n,m;
    static int s,t;
    static ArrayList<Pair>[] adj;
    static int[] dist;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
     
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        dist = new int[n + 1];
        adj = new ArrayList[n + 1];
        for (int i=1; i<=n; i++) adj[i] = new ArrayList<>();

        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            adj[a].add(new Pair(b, c));
            adj[b].add(new Pair(a, c));
        }

        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
    }

    public static class Pair implements Comparable<Pair> {
        int n;
        int dist;

        public Pair(int n, int dist) {
            this.n = n;
            this.dist = dist;
        }

        @Override
        public int compareTo(Pair p) {
            return this.dist - p.dist;
        } 
    }

    public static void main(String[] args) throws IOException {
        input();
        Arrays.fill(dist, Integer.MAX_VALUE);

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        dist[s] = 0;
        pq.add(new Pair(s, 0));

        while (!pq.isEmpty()) {
            Pair cur = pq.poll();

            if (dist[cur.n] < cur.dist) continue;

            for (Pair next : adj[cur.n]) {
                int nextDist = cur.dist + next.dist;
                if (nextDist > dist[next.n]) continue;
                dist[next.n] = nextDist;
                pq.add(new Pair(next.n, nextDist));
            }
        }
    
        System.out.println(dist[t]);
    }
}