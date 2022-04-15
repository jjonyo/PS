/* 
    프로그래머스 : 전력망을 둘로 나누기
*/

import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int solution(int n, int[][] wires) {
        int answer = Integer.MAX_VALUE;
        
        boolean[][] adj = new boolean[101][101];
        
        for (int i=0; i< n - 1; i++) {
            int a = wires[i][0];
            int b = wires[i][1];
            
            adj[a][b] = true;
            adj[b][a] = true;
        }
        
        for (int cur = 1; cur <= n; cur++) {
            for (int j = 1; j<= n; j++) {
                if (cur == j || !adj[cur][j]) continue;
                
                adj[cur][j] = false;
                adj[j][cur] = false;
                //cur, j에 대해 BFS 수행
                
                int aCount = bfs(n, adj, cur);
                int bCount = bfs(n, adj, j);
            
                //두개의 차이 절대값 계산
                answer = Math.min(answer, Math.abs(aCount - bCount));
                
                adj[cur][j] = true;
                adj[j][cur] = true;
            }
        }
        
        return answer;
    }
    
    int bfs(int n, boolean[][] adj, int start) {
        
        
        Queue<Integer> Q = new LinkedList<>();
        boolean[] visit = new boolean[n + 1];
        
        int count = 0;
        Q.add(start);
        visit[start] = true;
        
        while (!Q.isEmpty()) {
            count ++;
            int cur = Q.poll();
            
            for (int i=1; i<=n; i++) {
                if (!adj[cur][i]) continue;
                if (visit[i]) continue;
                visit[i] = true;
                Q.add(i);
            }
        }
        
        return count;
    }
}