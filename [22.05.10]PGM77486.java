/*
    2022.05.10
    PGM : 77486 다단계 칫솔 판매 (https://programmers.co.kr/learn/courses/30/lessons/77486)
    Algorithm : 트리
*/

import java.util.LinkedHashMap;
import java.util.Map;

class Solution {

  static Map<String, Member> memberMap = new LinkedHashMap<>();

  public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
    int N = enroll.length;

    for (int i=0;i<N;i++) {
      String name = enroll[i];
      String refName = referral[i];

      Member refMember = null;
      if (!refName.equals("-")) {
        refMember = memberMap.get(refName);
      }

      memberMap.put(name, new Member(name, refMember));
    }

    for (int i=0; i<seller.length; i++) {
      String sellerName = seller[i];
      int money = amount[i];

      Member member = memberMap.get(sellerName);
      dfs(member, money * 100);
    }

    return memberMap.values()
        .stream()
        .mapToInt(m -> m.money)
        .toArray();
  }

  public void dfs(Member cur, int money) {
    if (money < 10) {
      cur.money += money;
      return;
    }

    int div = money / 10;
    cur.money += (money - div);
    if (cur.referral != null) {
      dfs(cur.referral, div);
    }
  }

  public class Member {
    String name;
    Member referral;
    int money;

    public Member(String name, Member referral) {
      this.name = name;
      this.referral = referral;
      this.money = 0;
    }
  }
}
