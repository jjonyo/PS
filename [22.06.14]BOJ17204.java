/*
    2022.06.14
    BOJ : 17204 죽음의게임 (https://www.acmicpc.net/problem/17204)
    Algorithm : BFS 
*/

import java.util.*;
import java.io.*;

public class BOJ17204 {

    static int N, K;
    static int[] adj;
    static boolean[] vis;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        adj = new int[N];
        vis = new boolean[N];

        for (int i=0; i<N; i++) {
            int n = Integer.parseInt(br.readLine());
            adj[i] = n;
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        Queue<Integer> q = new LinkedList<>();

        q.add(0);
        vis[0] = true;

        int cnt = 0;
        while (!q.isEmpty()) {
            int cur = q.poll();

            if (cur == K) {
                System.out.println(cnt);
                return;
            }

            int next = adj[cur];
            if (vis[next]) continue;
            vis[next] = true;
            q.add(next);
            cnt += 1;
        }

        System.out.println(-1);
    }
}