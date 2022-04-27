/*
    2022.04.27
    BOJ : 18223 민준이와 마산 그리고 건우 (https://www.acmicpc.net/problem/18223)
    Algorithm : 다익스트라
*/

import java.util.*;
import java.io.*;

public class BOJ18223 {

    static int V,E,P;
    static ArrayList<Edge>adj[];
    static int[] dist1;
    static int[] dist2;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());

        dist1 = new int[V + 1];
        dist2 = new int[V + 1];
        adj = new ArrayList[V + 1];

        for (int i=1;i<=V;i++) adj[i] = new ArrayList<>();

        for (int i=0; i<E; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            adj[a].add(new Edge(b, d));
            adj[b].add(new Edge(a, d));
        }
    }

    public static void dijkstra(int start, int[] dist) {
        PriorityQueue<Info> PQ = new PriorityQueue<>();
        for (int i=1; i<=V; i++) dist[i] = Integer.MAX_VALUE;

        dist[start] = 0;
        PQ.add(new Info(start, 0));

        while (!PQ.isEmpty()) {
            Info cur = PQ.poll();

            if (dist[cur.idx] < cur.num) continue;
            dist[cur.idx] = cur.num;

            for (Edge next : adj[cur.idx]) {
                int nextDist = dist[cur.idx] + next.dist;

                if (nextDist < dist[next.to]) {
                    PQ.add(new Info(next.to, nextDist));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        dijkstra(1, dist1);        
        dijkstra(P, dist2);

        if (dist1[P] + dist2[V] <= dist1[V]) {
            System.out.println("SAVE HIM");
        } else {
            System.out.println("GOOD BYE");
        }
    }

    public static class Edge {
        int to;
        int dist;

        public Edge(int to, int dist) {
            this.to = to;
            this.dist = dist;
        }
    }

    public static class Info implements Comparable<Info>{
        int idx;
        int num;

        public Info(int idx, int num) {
            this.idx = idx;
            this.num = num;
        }

        @Override
        public int compareTo(Info i) {
            return num - i.num;
        }
    }
}