/*
	2022.04.18
	PGM : 17683 [3차] 방금 그곡 (https://programmers.co.kr/learn/courses/30/lessons/17683)
	Algorithm : 구현
    - '#'이 붙은 문자는 다른 문자로 치환해서 풀면 indexOf를 이용해 더 간단하게 풀이 가능
*/
import java.util.*;

class Solution {
    public String solution(String m, String[] musicinfos) {
        String answer = "";
        int max_len = 0;
        
        List<String> mList = parseMusic(m);
        
        for (String musicinfo : musicinfos) {
            StringTokenizer st = new StringTokenizer(musicinfo, ",");
            String startTime = st.nextToken();
            String endTime = st.nextToken();
            String title = st.nextToken();
            List<String> music = parseMusic(st.nextToken());
            
            int playTime = calculateTime(startTime, endTime);
            
            List<String> validMusic = toValidMusic(music, playTime);
            
            if (isContains(mList, validMusic)) {
                if (playTime > max_len) {
                    max_len = playTime;
                    answer = title;
                }
            }
        }
        
        if (answer.equals("")) {
            answer = "(None)";
        }
        return answer;
    }
    
    boolean isContains(List<String> m, List<String> music) {
        if (m.size() > music.size()) return false;
        
        int size = m.size();
        boolean isContain = false;
        
        for (int i=0; i<= music.size() - size; i++) {
            int idx = 0;
            while (idx < size) {
                if (!m.get(idx).equals(music.get(i + idx)))
                    break;
                idx++;
            }
            if (idx == size) {
                isContain = true;
                break;
            }
        }
        
        return isContain;
    }
    
    List<String> toValidMusic(List<String> music, int playTime) {
        List<String> ret = new ArrayList<>();
        if (playTime < music.size()) {
            for (int i = 0; i<playTime; i++) {
                ret.add(music.get(i));
            }
        } else {
            int i = 0;
            int cnt = 0;
            while (cnt < playTime) {
                ret.add(music.get(i));
                cnt++;
                i++;
                if (i == music.size()) i = 0;
            }
        }
        
        return ret;
    }
    
    List<String> parseMusic(String music) {
        List<String> list = new ArrayList<>();
        
        for (int i=0; i<music.length(); i++) {
            if (i + 1 < music.length() && music.charAt(i + 1) == '#') {
                list.add(Character.toString(music.charAt(i)) + Character.toString(music.charAt(i + 1)));
                i++;
                continue;
            }
            list.add(Character.toString(music.charAt(i)));
        }
        
        return list;
    }
    
    int calculateTime(String start, String end) {
        String[] startString = start.split(":");
        String[] endString = end.split(":");
        
        int startTime = Integer.parseInt(startString[0]) * 60 + Integer.parseInt(startString[1]);
        int endTime = Integer.parseInt(endString[0]) * 60 + Integer.parseInt(endString[1]);
        
        
        return endTime - startTime;
    }
}