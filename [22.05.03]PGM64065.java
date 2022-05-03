/*
    2022.05.03
    PGM : 64065 튜플 (https://programmers.co.kr/learn/courses/30/lessons/64065)
    Algorithm : 구현
*/

import java.util.*;


class Solution {
    public int[] solution(String s) {
        ArrayList<Integer> answer = new ArrayList<>();
        boolean[] count = new boolean[100001];
        
        s = s.substring(1, s.length() - 1);

        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        
        ArrayList<Integer> list = null;
        StringBuilder sb = new StringBuilder();
        for (int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            
            if (c == '{') {
                sb.setLength(0);
                list = new ArrayList<>();
            } else if (c == '}') {
                StringTokenizer st = new StringTokenizer(sb.toString(), ",");
                while(st.hasMoreTokens()) {
                    list.add(Integer.parseInt(st.nextToken()));
                }
                arr.add(list);
            }else {
                sb.append(c);
            }
        }
        
        Collections.sort(arr, new Comparator<ArrayList<Integer>>() {
            @Override
            public int compare(ArrayList<Integer> a1, ArrayList<Integer> a2) {
                return a1.size() - a2.size();
            }
        });
        
        for (ArrayList<Integer> a : arr) {
            
            for (int n : a) {
                if (!count[n]) {
                    count[n] = true;
                    answer.add(n);
                    break;
                }
            }
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }
}