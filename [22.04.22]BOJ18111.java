/*
	2022.04.22
	BOJ : 18111 마인크래프트 (https://www.acmicpc.net/problem/18111)
	Algorithm : 완전탐색
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

import javax.sound.sampled.SourceDataLine;

public class BOJ18111 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        int[][] map = new int[N][M];
        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0;j<M;j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        Set<Integer> set = new HashSet<>();
        for (int i=0; i<N; i++) {
            for (int j=0;j<M;j++) {
                int num = map[i][j];
                if (set.contains(num)) continue;
                set.add(num);
            }
        }
        int max_value = set.stream().mapToInt(i -> i).max().orElse(256);
        int min_value = set.stream().mapToInt(i -> i).min().orElse(0);

        int answer = Integer.MAX_VALUE;
        int answer_block = Integer.MIN_VALUE;
        for (int n = min_value; n <=max_value; n++) {
            int addCount = 0;
            int removeCount = 0;
            int time = 0;
            for (int i=0; i<N; i++) {
                for (int j=0; j<M; j++) {
                    int num = map[i][j];
                    int diff;
                    if (num > n) {
                        diff = num - n;
                        time += diff * 2;
                        removeCount += diff;
                    } else if (num < n) {
                        diff = n - num;
                        time += diff;
                        addCount += diff;
                    }
                }
            }
            if (B + removeCount < addCount) continue;
            if (time <= answer) {
                answer = time;
                if (answer == time) {
                    answer_block = Math.max(answer_block, n);
                } else {
                    answer_block = n;
                }
            }
        }
        System.out.println(answer + " " + answer_block);
    }
}
