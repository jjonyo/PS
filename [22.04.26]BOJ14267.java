/*
    2022.04.26
    BOJ : 14267 회사 문화1 (https://www.acmicpc.net/problem/14267)
    Algorithm : DFS
*/

import java.util.*;
import java.io.*;

public class BOJ14267 {

    static int N, M;
    static int[] arr;
    static int[] score;
    static ArrayList<Integer>[] child;    

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        child = new ArrayList[N + 1];
        score = new int[N + 1];
        arr = new int[N + 1];

        for (int i=1; i<=N; i++) {
            child[i] = new ArrayList<>();
        }

        st = new StringTokenizer(br.readLine());
        for (int i=1; i<=N; i++) {
            int num = Integer.parseInt(st.nextToken());
            if (num == -1) continue;
            child[num].add(i);
        }
        
        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());

            int num = Integer.parseInt(st.nextToken());
            int good = Integer.parseInt(st.nextToken());

            arr[num] += good;
        }
    }
    
    static void dfs(int node, int s) {
        score[node] += arr[node] + s;

        for (int next : child[node]) {
            dfs(next, score[node]);
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        dfs(1, 0);
        
        StringBuilder sb = new StringBuilder();
        for (int i=1; i<=N; i++) {
            sb.append(score[i]).append(" ");
        }
        
        System.out.println(sb.toString());
    }
}