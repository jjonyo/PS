/*
    2022.06.05
    PGM : 12914 멀리 뛰기 (https://programmers.co.kr/learn/courses/30/lessons/12914)
    Algorithm : DP
*/

class Solution {
    public long solution(int n) {
        long[] dp = new long[2001];
        
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i= 3; i<=2000; i++) {
            dp[i] = (dp[i - 2] + dp [i - 1]) % 1234567;
        }
        
        return dp[n];
    }
}