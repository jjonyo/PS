/*
    2022.04.23
    BOJ : 20291 파일 정리 (https://www.acmicpc.net/problem/20291)
    Algorithm : 해시맵
*/

import java.util.*;
import java.io.*;

public class BOJ20291 {
    static HashMap<String, Integer> map = new HashMap<>();

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        int N = Integer.parseInt(br.readLine());

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine(), "."); 
            String name = st.nextToken();
            String file = st.nextToken();

            if (map.containsKey(file)) {
                int num = map.get(file);
                map.put(file, num + 1);
            } else {
                map.put(file, 1);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        Object[] arr = map.keySet().toArray();
        Arrays.sort(arr);

        for (Object key : arr) {
            System.out.println(key.toString() + " " + map.get(key));
        }
    }
}