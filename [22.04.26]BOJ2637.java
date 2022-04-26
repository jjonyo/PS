/*
    2022.04.26
    BOJ : 2637 장난감 조립 (https://www.acmicpc.net/problem/2637)
    Algorithm : 위상정렬, DP
*/

import java.util.*;
import java.io.*;

public class BOJ2637 {

    static int N, M;
    static ArrayList<Pair>[] adj;
    static int[] indegree;
    static int[] count;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        adj = new ArrayList[N + 1];
        for (int i=1; i<=N; i++) {
            adj[i] = new ArrayList<Pair>();
        }

        indegree = new int[N+1];
        count = new int[N+1];

        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());

            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int len = Integer.parseInt(st.nextToken());

            indegree[to]++;
            adj[from].add(new Pair(to, len));
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        Queue<Pair> Q = new LinkedList<>();
        Q.add(new Pair(N, 1));

        while (!Q.isEmpty()) {
            Pair cur = Q.poll();

            for (Pair next : adj[cur.n]) {
                count[next.n] += cur.w * next.w;

                indegree[next.n]--;
                if (indegree[next.n] == 0) 
                    Q.add(new Pair(next.n, count[next.n]));
            }
        }

        for (int i=1;i<=N;i++) {
            if (adj[i].isEmpty()) {
                System.out.println(i + " " + count[i]);
            }
        }
    }

    public static class Pair {
        int n, w;

        public Pair(int n, int w) {
            this.n = n;
            this.w = w;
        }
    }
}