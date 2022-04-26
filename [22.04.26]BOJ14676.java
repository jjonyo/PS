/*
    2022.04.26
    BOJ : 14676 영우는 사기꾼? (https://www.acmicpc.net/problem/14676)
    Algorithm : 위상정렬
*/

import java.util.*;
import java.io.*;

public class BOJ14676 {

    static int N, M, K;
    static int[] count;
    static ArrayList<Integer>[] adj;
    static int[] indegree;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void input() throws IOException {

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        count = new int[N + 1];
        adj = new ArrayList[N + 1];
        indegree = new int[N + 1];
        
        for (int i=1;i<=N;i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            adj[from].add(to);
            indegree[to]++;
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        for (int i=0; i<K; i++) {
            st = new StringTokenizer(br.readLine());

            int command = Integer.parseInt(st.nextToken());
            int num = Integer.parseInt(st.nextToken());

            if (command == 1) { //건설
                boolean isValid = true;

                if (indegree[num] > 0) {
                    System.out.println("Lier!");
                    return;
                }

                //지을 수 있으면 건물을 짓는다.
                count[num]++;

                if (count[num] == 1){
                    for (int next : adj[num]) {
                        indegree[next]--;
                    }
                }
            } else if (command == 2) { //파괴
                //지은 적 있는 건물인지 확인
                if (count[num] == 0) {
                    System.out.println("Lier!");
                    return;
                }
                
                //건물 파괴
                count[num]--;
                if (count[num] == 0) {
                    for (int next : adj[num]) {
                        indegree[next]++;
                    }
                }
            }
        }
        System.out.println("King-God-Emperor");
    }
}