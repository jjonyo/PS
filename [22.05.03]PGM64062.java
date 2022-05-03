/*
    2022.05.03
    PGM : 64062 징검다리 건너기 (https://programmers.co.kr/learn/courses/30/lessons/64062)
    Algorithm : 이분탐색
*/

class Solution {
    public int solution(int[] stones, int k) {
        int answer = 0;
        
        int start = 1;
        int end = Integer.MAX_VALUE;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (isAble(stones, mid, k)) {
                start = mid + 1;
                answer = Math.max(answer, mid);
            } else {
                end = mid - 1;
            }
        }

        return answer;
    }
    
    //n일때 건너려먼 n-1만큼 받고 그 다음 사람이 건널 수 있어야 한다.
    public boolean isAble(int[] stones, int n, int k) {
        int[] copyStones = new int[stones.length];
        
        for (int i=0;i<stones.length;i++) copyStones[i] = stones[i] - (n - 1);
        
        int cnt = 0;
        for (int i=0; i<copyStones.length; i++) {          
            if (copyStones[i] <= 0) {
                cnt++;
            } else {
                cnt = 0;
            }
            
            if (cnt >= k) return false;
        }
        
        return true;
    }
}