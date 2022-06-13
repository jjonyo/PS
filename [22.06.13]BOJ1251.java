/*
    2022.06.13
    BOJ : 1251 단어나누기 (https://www.acmicpc.net/problem/1251)
    Algorithm : 구현
*/

import java.util.*;
import java.io.*;

public class BOJ1251 {

    static String word;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        word = br.readLine();
    }

    public static void main(String[] args) throws IOException {
        input();

        int N = word.length();
        List<String> result = new ArrayList<>();

        for (int i=1; i < N - 1; i++) {
            for (int j = i + 1; j <N; j++) {
                //세 단어로 나누기
                String first = word.substring(0, i);
                String second = word.substring(i, j);
                String third = word.substring(j, N);

                result.add(reverse(first) + reverse(second) + reverse(third));
            }
        }

        Collections.sort(result);

        System.out.println(result.get(0));
    }

    public static String reverse(String str) {
        StringBuilder sb = new StringBuilder(str);

        return sb.reverse().toString();
    }
}