/*
    2022.05.04
    PGM : 67259 경주로 건설 (https://programmers.co.kr/learn/courses/30/lessons/67259)
    Algorithm : BFS, DP
*/
import java.util.*;

class Solution {
    static int min = Integer.MAX_VALUE;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static int[][][] vis;
    static int N;
    
    public void bfs(int[][] board) {
        Queue<Info> q = new LinkedList<>();
        vis[0][0][0] = vis[1][0][0] = vis[2][0][0] = vis[3][0][0] = 0;
        q.add(new Info(0, 0, -1, 0));
        
        while (!q.isEmpty()) {
            Info cur = q.poll();

            if (cur.r == N-1 && cur.c == N-1) {
                min = Math.min(min, cur.cost);
            }
            
            for (int dir=0; dir<4; dir++) {
                int nr = cur.r + dx[dir];
                int nc = cur.c + dy[dir];

                if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                if (board[nr][nc] == 1) continue;
                int cost = 0;
                if (cur.prev != -1 && cur.prev != dir)
                    cost = 600;
                else 
                    cost = 100;
                int nextCost = cost + cur.cost;
                if (vis[dir][nr][nc] < nextCost) continue;
                vis[dir][nr][nc] = nextCost;
                q.add(new Info(nr, nc, dir, nextCost));
            }
        }
        
    }
    
    
    public int solution(int[][] board) {
        int answer = 0;
        
        N = board.length;
        vis = new int[4][N][N];
        for (int i=0;i<4;i++) {
            for (int j=0;j<N;j++) {
                Arrays.fill(vis[i][j], Integer.MAX_VALUE);
            }
        }
        
        bfs(board);
        answer=min;
        return answer;
    }
    
    public class Info {
        int r;
        int c;
        int prev;
        int cost;
        
        public Info(int r, int c,int prev, int cost) {
            this.r = r;
            this.c = c;
            this.prev = prev;
            this.cost = cost;
        }
    }
}