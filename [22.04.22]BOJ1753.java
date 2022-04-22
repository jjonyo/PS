/*
	2022.04.22
	BOJ : 1753 최단경로 (https://www.acmicpc.net/problem/1753)
	Algorithm : 다익스트라
*/
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class BOJ1753 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        PriorityQueue<Edge> pq = new PriorityQueue<>();

        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        int startNumber = Integer.parseInt(br.readLine());
        ArrayList<Edge>[] adj = new ArrayList[V + 1];
        for (int i=0; i<V + 1; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i=0; i<E; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            adj[from].add(new Edge(to, w));
        }

        int[] dist = new int[V + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        dist[startNumber] = 0;
        pq.add(new Edge(startNumber, 0));

        while (!pq.isEmpty()) {
            Edge cur = pq.poll();

            if (dist[cur.index] < cur.dist) continue;

            for (Edge next : adj[cur.index]) {
                if (cur.dist + next.dist < dist[next.index]) {
                    dist[next.index] = cur.dist + next.dist;
                    pq.add(new Edge(next.index, dist[next.index]));
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i=1; i<=V; i++) {
            int num = dist[i];
            if (num == Integer.MAX_VALUE) {
                sb.append("INF\n");
            } else {
                sb.append(num).append("\n");
            }
        }
        System.out.println(sb.toString());
    }

    public static class Edge implements Comparable<Edge> {
        int index;
        int dist;

        Edge(int index, int dist) {
            this.index = index;
            this.dist =dist;
        }

        @Override
        public String toString() {
            return "[index : " + this.index + ", dist : " + this.dist + "]";
        }

        @Override
        public int compareTo(Edge e) {
            return this.dist - e.dist;
        }
    }
}
