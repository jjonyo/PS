/*
    2022.05.06
    PGM : 42889 실패율 (https://programmers.co.kr/learn/courses/30/lessons/42889)
    Algorithm : 정렬 
*/
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
  public int[] solution(int N, int[] stages) {
    ArrayList<Info> answer = new ArrayList<>();

    int n = 1;
    int idx = 0;
    int count = 0;
    int len = stages.length;
    Arrays.sort(stages);
    while (n <= N) {
      count = 0;
      for (; idx < len; idx++) {
        if (stages[idx] != n) {
          break;
        }
        count++;
      }
      int m = len - idx + count;
      double rate = 0;
      if (m == 0) {
        rate = 0;
      } else {
        rate = (double) count / m;
      }
      answer.add(new Info(rate, n));
      n++;
    }

    answer.sort((o1, o2) -> Double.compare(o2.rate, o1.rate));

    return answer.stream().map(Info -> Info.num).mapToInt(i -> i).toArray();
  }

  public static class Info {

    double rate;
    int num;

    public Info(double rate, int num) {
      this.rate = rate;
      this.num = num;
    }
  }
}
