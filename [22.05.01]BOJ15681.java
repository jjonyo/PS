/*
    2022.05.01
    BOJ : 15681 트리와 쿼리 (https://www.acmicpc.net/problem/15681)
    Algorithm : DP
*/

import java.util.*;
import java.io.*;

public class BOJ15681 {

    static int N,R,Q;
    static ArrayList<Integer>[] adj;
    static int[] dp;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void input() throws IOException {
        st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        adj = new ArrayList[N + 1];
        for (int i=1; i<=N; i++) adj[i] = new ArrayList<>();

        for (int i=0; i<N - 1; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
         
            adj[a].add(b);
            adj[b].add(a);
        }

        dp = new int[N + 1];
    }

    static int dfs(int n) {
        dp[n] = 1;

        for (int next : adj[n]) {
            if (dp[next] != 0) continue;
            dp[n] += dfs(next);
        }

        return dp[n];
    }

    public static void main(String[] args) throws IOException {
        input();

        dfs(R);

        for (int i=0;i<Q; i++) {
            int num = Integer.parseInt(br.readLine());

            System.out.println(dp[num]);
        }
        
    }

}