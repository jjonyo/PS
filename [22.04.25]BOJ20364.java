/*
    2022.04.25
    BOJ : 20364 부동산 다툼 (https://www.acmicpc.net/problem/20364)
    Algorithm : 트리
*/

import java.util.*;
import java.io.*;

public class BOJ20364 {

    static int N;
    static int Q;

    static boolean[] tree;
    static int[] duck;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
    
        duck = new int[Q];
        for (int i=0;i<Q;i++) {
            duck[i] = Integer.parseInt(br.readLine());
        }

        tree = new boolean[1<<20 + 1];
    }

    public static void main(String[] args) throws IOException {
        input();

        StringBuilder sb = new StringBuilder();
        for (int i=0; i<Q; i++) {
            int d = duck[i];
            boolean success = true;
            int failNode = 0;

            //갈 수 있는지 확인
            while (d > 0) {
                if (tree[d]) {
                    success = false;
                    failNode = d;
                }
                d /= 2;
            }

        
            if (success) {
                tree[duck[i]] = true;
                sb.append(0).append("\n");
            } else {
                sb.append(failNode).append("\n");
            }
        }
        System.out.println(sb.toString());
    }
}