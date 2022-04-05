import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class BOJ2563 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    int N = Integer.parseInt(br.readLine());

    boolean[][] board = new boolean[102][102];

    for (int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine(), " ");

      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());

      for (int j=0; j<10; j++) {
        for (int k=0; k<10; k++) {
          board[a + j][b + k] = true;
        }
      }
    }
    int ans = 0;
    for (int j=0; j<102;j++) {
      for (int k=0; k<102; k++) {
        if (board[j][k] == true) ans++;
      }
    }
    System.out.println(ans);
  }
}
