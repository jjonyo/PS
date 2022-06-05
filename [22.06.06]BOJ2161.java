/*
    2022.00.00
    BOJ : 0 이름 (https://www.acmicpc.net/problem/0)
    Algorithm : 
*/

import java.util.*;
import java.io.*;

public class BOJ2161 {

    static int N;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
    }

    public static void main(String[] args) throws IOException {
        input();

        StringBuilder ans = new StringBuilder();
        Queue<Integer> q = new LinkedList<>();

        for (int i=1; i<=N; i++) {
            q.add(i);
        }

        while (!q.isEmpty()) {
            ans.append(q.poll()).append(" ");
            if (q.isEmpty()) break;
            q.add(q.poll());
        }

        System.out.println(ans);
    }
}