/*
    2022.06.07
    BOJ : 1835 카드 (https://www.acmicpc.net/problem/1835)
    Algorithm : 덱
*/

import java.util.*;
import java.io.*;

public class BOJ1835 {

    static int N;
    static Deque<Integer> dq = new LinkedList<>();

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
    }

    public static void main(String[] args) throws IOException {
        input();

        dq.add(N);

        for (int i = N - 1; i>0; i--) {
            dq.addFirst(i);

            for (int j=0;j<i;j++) {
                dq.addFirst(dq.pollLast());
            }
        }
        dq.forEach(i -> System.out.print(i + " "));
    }

}