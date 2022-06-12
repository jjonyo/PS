/*
    2022.06.12
    BOJ : 15624 피보나치수 2 (https://www.acmicpc.net/problem/15624)
    Algorithm : DP
*/

import java.io.*;

public class BOJ15624 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        if (n == 0) {
            System.out.println(0);
            return;
        }
        long[] dp = new long[n + 1];

        dp[0] = 0;
        dp[1] = 1;

        for (int i=2; i<=n; i++) {
            dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
        }

        System.out.println(dp[n]);
    }
}