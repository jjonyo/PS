/*
	2022.04.20
	BOJ : 2775 부녀회장이 될테야 (https://www.acmicpc.net/problem/2775)
	Algorithm : DP
*/
import java.util.Scanner;

public class BOJ2775 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for (int i=0;i<T;i++) {
            int k = sc.nextInt();
            int n = sc.nextInt();

            int[][] dp = new int[k + 1][n + 1];

            for (int room = 1; room <=n; room++) {
                dp[0][room] = room;
            }
            for (int floor = 0; floor <= k; floor++) {
                dp[floor][1] = 1;
            }

            for (int floor = 1; floor <= k; floor++) {
                for (int room = 1; room <= n; room++) {
                    dp[floor][room] = dp[floor][room - 1] + dp[floor - 1][room];
                }
            }

            System.out.println(dp[k][n]);
        }
    }
}
