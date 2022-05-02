/*
    2022.05.02
    BOJ : 20166 문자열 지옥에 빠진 호석 (https://www.acmicpc.net/problem/20166)
    Algorithm : 완전탐색
*/

import java.util.*;
import java.io.*;

public class BOJ20166 {

    static int N,M,K;
    static char[][] map;
    static int[] dr = new int[]{-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dc = new int[]{0, 1, 1, 1, 0, -1, -1, -1};
    static Map<String, Integer> answer = new HashMap<>();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


    public static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        map = new char[N][];
        for (int i=0;i<N;i++) {
            map[i] = br.readLine().toCharArray();
        }
    }

    public static void solve(int r, int c, String path, int cnt) {
    
        if (answer.containsKey(path)) answer.put(path, answer.get(path) + 1);
        else answer.put(path, 1);
        
        if (cnt == 5) return;

        for (int dir = 0; dir < 8; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            
            if (nr == -1) nr = N - 1;
            else if (nr == N) nr = 0;
            if (nc == -1) nc = M - 1;
            else if (nc == M) nc = 0;

            solve(nr, nc, path + map[nr][nc], cnt + 1);
        }
     }

    public static void main(String[] args) throws IOException {
        input();
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                solve(i, j, Character.toString(map[i][j]), 0);
            }
        }

        for (int i=0;i<K;i++) {
            String word = br.readLine();
            if (answer.containsKey(word)) 
                System.out.println(answer.get(word));
            else
                System.out.println(0);
        }
    }
}