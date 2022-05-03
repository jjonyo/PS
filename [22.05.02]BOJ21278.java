/*
    2022.05.03
    BOJ : 21278 호석이 두 마리 치킨 (https://www.acmicpc.net/problem/21278)
    Algorithm : BFS, 완전탐색
*/

import java.util.*;
import java.io.*;

public class BOJ21278 {

    static int N,M;
    static ArrayList<Integer>[] adj;
    static int[][] dist;
    static boolean[] vis;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        adj = new ArrayList[N + 1];
        for (int i=1; i<=N; i++) adj[i] = new ArrayList<>();

        dist = new int[N + 1][N + 1];
        vis = new boolean[N + 1];

        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            adj[a].add(b);
            adj[b].add(a);
        }
    }

    public static void BFS(int start) {
        Arrays.fill(vis, false);

        Queue<Integer> q = new LinkedList<>();
        vis[start] = true;
        dist[start][start] = 0;
        q.add(start);

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int next : adj[cur]) {
                if (vis[next]) continue;
                q.add(next);
                dist[start][next] = dist[start][cur] + 1;
                vis[next] = true;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        //모든 정점에 대하여 BFS를 한다.
        for (int i=1; i<=N; i++) {
            BFS(i);
        }

        int min = Integer.MAX_VALUE;
        int ans1 = 0;
        int ans2 = 0;
        for (int i=1; i <= N - 1; i++) {
            for (int j=i+1; j<=N; j++) {
                int sum = 0;

                for (int k=1; k<=N; k++) {
                    if (k == i || k == j) continue;
                    sum += Math.min(dist[k][i], dist[k][j]);
                }

                if (sum < min) {
                    min = sum;
                    ans1 = i;
                    ans2 = j;
                }
            }
        }
        System.out.println(ans1 + " " + ans2 + " " + min * 2);
    }
}