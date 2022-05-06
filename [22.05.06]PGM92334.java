/*
    2022.05.06
    PGM : 92334 신고 결과 받기 (https://programmers.co.kr/learn/courses/30/lessons/92334)
    Algorithm : 구현
*/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution {

  static Map<String, Set<String>> map = new LinkedHashMap<>();
  static Map<String, Integer> count = new HashMap<>();

  public int[] solution(String[] id_list, String[] report, int k) {

    for (String id : id_list) {
      map.put(id, new HashSet<>());
      count.put(id, 0);
    }

    for (String log : report) {
      String[] split = log.split(" ");


      if (map.get(split[0]).contains(split[1])) continue;
      map.get(split[0]).add(split[1]);
      count.put(split[1], count.get(split[1]) + 1);
    }

    List<Integer> answer = new ArrayList<>();

    for (Set<String> s : map.values()) {
      int cnt = 0;
      for (String name : s) {
        if (count.get(name) >= k) {
         cnt++;
        }
      }
      answer.add(cnt);
    }

    return answer.stream().mapToInt(i -> i).toArray();
  }
}
