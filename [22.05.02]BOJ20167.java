/*
    2022.05.02
    BOJ : 20167 꿈틀꿈틀 호석 애벌레 - 기능성 (https://www.acmicpc.net/problem/20167)
    Algorithm : 완전탐색
*/

import java.util.*;
import java.io.*;

public class BOJ20167 {

    static int N,K;
    static int[] arr;
    static int ans = 0;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        arr = new int[N];
        
        st = new StringTokenizer(br.readLine());
        for (int i=0; i<N;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    public static void dfs(int n, int sum, int score) {        
        if (n == N) {
            ans = Math.max(ans, score);
            return;
        }
        if (sum == 0) dfs(n + 1, sum, score);

        sum += arr[n];
        if (sum >= K) {
            score += sum - K;
            sum = 0;
        }
        dfs(n + 1, sum, score);
    }

    public static void main(String[] args) throws IOException {
        input();

        dfs(0, 0, 0);

        System.out.println(ans);
    }
}