/*
    2022.05.03
    BOJ : 20168 골목 대장 호석-기능성 (https://www.acmicpc.net/problem/20168)
    Algorithm : DFS
*/

import java.util.*;
import java.io.*;

public class BOJ20168 {

    static int N,M,A,B,C;
    static ArrayList<Pair>[] adj;
    static boolean[] vis;
    static int ans = Integer.MAX_VALUE;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        vis = new boolean[N + 1];
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

    public static void dfs(int cur, int maximum, int money) {
        if (cur == B) {
            ans = Math.min(ans, maximum);
            return;
        }

        for (Pair next : adj[cur]) {
            int max = Math.max(maximum, next.cost);

            if (money + next.cost > C) continue;
            if (vis[next.to]) continue;
            vis[next.to] = true;
            dfs(next.to, max, money + next.cost);
            vis[next.to] = false;
        }
    }
 
    public static void main(String[] args) throws IOException {
        input();


        vis[A] = true;
        dfs(A, 0, 0);

        System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
    }

    public static class Pair {
        int to;
        int cost;

        public Pair(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }
}