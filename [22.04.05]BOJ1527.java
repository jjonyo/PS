import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1527 {
  static int A;
  static int B;
  static int ans = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine(), " ");

    A = Integer.parseInt(st.nextToken());
    B = Integer.parseInt(st.nextToken());

    for (int i=1; i<10;i++)
    {
      StringBuilder sb = new StringBuilder();
      solve(0, i, sb);
    }

    System.out.println(ans);
  }


  static void solve(int cur, int num, StringBuilder sb) {
    if (cur == num) {
      int number = Integer.parseInt(sb.toString());

      if (A <= number && B >= number)
        ans ++;
      return;
    }
    sb.append('4');
    solve(cur + 1, num, sb);
    sb.setLength(sb.length() - 1);
    sb.append('7');
    solve(cur + 1, num, sb);
    sb.setLength(sb.length() - 1);
  }
}
