import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

class BOJ10798 {

  public static void main(String[] args) throws Exception {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    List<String> list = new ArrayList<>();

    String str;
    while ((str = br.readLine()) != null) {
      list.add(str);
    }
    int max = list.stream().mapToInt(s -> s.length()).max().getAsInt();

    StringBuilder ans = new StringBuilder();

    for (int i=0; i<max; i++) {
      for (int j=0; j<list.size(); j++) {
        if (list.get(j).length() <= i) continue;
        ans.append(list.get(j).charAt(i));
      }
    }
    System.out.println(ans);
  }
}
