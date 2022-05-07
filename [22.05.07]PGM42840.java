/*
    2022.05.07
    PGM : 42840 모의고사 (https://programmers.co.kr/learn/courses/30/lessons/42840)
    Algorithm : 구현
*/
import java.util.ArrayList;

class Solution {
    public int[] solution(int[] answers) {
        int[] student1 = {1, 2, 3, 4, 5};
        int[] student2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5,};
        
        int s1 = 0;
        int s1_idx = 0;
        int s2 = 0;
        int s2_idx = 0;
        int s3 = 0;
        int s3_idx = 0;
        
        for (int i=0; i<answers.length; i++) {
            if (s1_idx == student1.length) s1_idx = 0;
            if (s2_idx == student2.length) s2_idx = 0;
            if (s3_idx == student3.length) s3_idx = 0;
            
            if (answers[i] == student1[s1_idx++]) s1++;
            if (answers[i] == student2[s2_idx++]) s2++;
            if (answers[i] == student3[s3_idx++]) s3++;
        }
        
        int max = Math.max(s1, Math.max(s2, s3));
        ArrayList<Integer> ans = new ArrayList<>();
        
        if (s1 == max) ans.add(1);
        if (s2 == max) ans.add(2);
        if (s3 == max) ans.add(3);
        
        
        return ans.stream().mapToInt(i -> i).toArray();
    }
}