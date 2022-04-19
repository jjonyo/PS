import java.util.ArrayList;

/*
	2022.04.18
	PGM : 17684 [3차] 압축 (https://programmers.co.kr/learn/courses/30/lessons/17684)
	Algorithm : 구현
*/
class Solution {
    public int[] solution(String msg) {
        ArrayList<Integer> ans = new ArrayList<>();
        ArrayList<String> dict = new ArrayList<>();
        dict.add("");
        for (char c = 'A'; c <= 'Z'; c++) {
            dict.add(Character.toString(c));
        }
        
        int idx = 0;
        while (true) {
            if (idx >= msg.length()) break;
            int size = dict.size();
            String cur = "";
            for (int i = size - 1; i > 0; i--) {
                cur = dict.get(i);
                //사전에서 단어 찾음
                if (idx + cur.length() > msg.length()) continue;
                String sub = msg.substring(idx, idx + cur.length());
                if (sub.equals(cur)) {
                    ans.add(i);
                    if (idx + cur.length() < msg.length()) {
                        String temp = sub + Character.toString(msg.charAt(idx + cur.length()));
                        dict.add(temp);
                    }
                    break;
                }
            }
            idx += cur.length();
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}