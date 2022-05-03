/*
    2022.05.03
    PGM : 64064 불량 사용자 (https://programmers.co.kr/learn/courses/30/lessons/64064)
    Algorithm : DFS
*/

import java.util.HashSet;
import java.util.Arrays;

class Solution {
    static boolean[] check;
    static HashSet<String> ans = new HashSet<>();
    
    public int solution(String[] user_id, String[] banned_id) {
        int n = user_id.length;
        int k = banned_id.length;
        
        check = new boolean[n];
        Arrays.fill(check, false);
        
        dfs(0, n, k, user_id, banned_id);
        
        return ans.size();
    }
    
    public void dfs(int cnt, int n, int k, String[] user_id, String[] banned_id) {
        if (cnt == k) {
            StringBuilder sb = new StringBuilder();
            for (int i=0; i<n; i++) {
                if (check[i]) {
                    sb.append(i);
                }
            }
            ans.add(sb.toString());
            return;
        }
        
        for (int i=0;i<n;i++) {
            if (check[i]) continue;
            if (!isAble(user_id[i], banned_id[cnt])) continue;
            check[i] = true;
            dfs(cnt + 1, n, k, user_id, banned_id);
            check[i] = false;
        }
    }
    
    public boolean isAble(String str, String ban) {
        if (str.length() != ban.length()) return false;
        
        int len = str.length();
        
        for (int i=0;i<len;i++) {
            if (ban.charAt(i) == '*') continue;
            if (str.charAt(i) != ban.charAt(i)) return false;
        }
        
        return true;
    }
}