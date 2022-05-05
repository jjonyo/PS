/*
    2022.05.05
    PGM : 17686 파일명정렬 (https://programmers.co.kr/learn/courses/30/lessons/17686)
    Algorithm : 정렬
*/
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Solution {

  public String[] solution(String[] files) {
    ArrayList<Info> strs = new ArrayList<>();

    for (String file : files) {
      int idx = 0;
      //HEAD추출
      for (idx = 0; idx<file.length();idx++) {
        if (Character.isDigit(file.charAt(idx))) {
          break;
        }
      }

      String head = file.substring(0, idx);
      int s = idx;
      for (; idx < file.length(); idx++) {
        if (!Character.isDigit(file.charAt(idx))) {
          break;
        }
      }
      String number = file.substring(s, idx);

      strs.add(new Info(head.toLowerCase(), Integer.parseInt(number), file));
    }

    Collections.sort(strs, new Comparator<Info>() {
      @Override
      public int compare(Info o1, Info o2) {
        if (!o1.head.equals(o2.head)) return o1.head.compareTo(o2.head);
        return o1.number - o2.number;
      }
    });

    return strs.stream().map(info -> info.str).toArray(String[]::new);
  }

  public static class Info {
    String head;
    int number;
    String str;

    public Info(String head, int number, String str) {
      this.head = head;
      this.number = number;
      this.str = str;
    }
  }
}
