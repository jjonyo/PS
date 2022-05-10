/*
    2022.05.10
    PGM : 12971 스티커 모으기(2) (https://programmers.co.kr/learn/courses/30/lessons/12971)
    Algorithm : DP
*/
class Solution {

    public int solution(int sticker[]) {
  
      int N = sticker.length;
  
      if (N == 1) return sticker[0];
  
      int[] dp = new int[N];
      int[] dp2 = new int[N];
  
      dp[0] = sticker[0];
      dp[1] = sticker[0];
  
      dp2[0] = 0;
      dp2[1] = sticker[1];
  
      for (int i=2; i<N - 1; i++) {
        dp[i] = Math.max(dp[i - 2] + sticker[i], dp[i - 1]);
      }
  
      for (int i=2; i<N; i++) {
        dp2[i] = Math.max(dp2[i - 2] + sticker[i], dp2[i - 1]);
      }
  
      return Math.max(dp[N - 2], dp2[N - 1]);
    }
  }
  