/*
	2022.04.17
	PGM : 17682 [1차] 다읕 게임 (https://programmers.co.kr/learn/courses/30/lessons/17682)
	Algorithm : 스택
*/

import java.util.Stack;

class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        Stack<Integer> st = new Stack<>();
        
        for (int i=0; i<dartResult.length(); i++) {
            char c = dartResult.charAt(i);
            
            //숫자일 경우
            if (Character.isDigit(c)) {
                if (c == '1' && i + 1 < dartResult.length() && dartResult.charAt(i + 1) == '0') {
                    st.push(10);
                    i++;
                } else {
                    st.push(c - '0');
                }
            } else if (c == 'S' || c == 'D' || c == 'T') {
                int num = st.pop();
                if (c == 'D')
                    num = num * num;
                else if (c == 'T')
                    num = num * num * num;
                st.push(num);
            } else if (c == '*' || c == '#') {
                if (c == '#') {
                    int num = st.pop();
                    st.push(num * -1);
                } else if (c == '*') {
                    int first = st.pop();
                    if (!st.isEmpty()) {
                        int second = st.pop();
                        st.push(second * 2);
                    }
                    st.push(first * 2);
                }
            }
        }
        while (!st.isEmpty()) {
            answer += st.pop();
        }
        return answer;
    }
}