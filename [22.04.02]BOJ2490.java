import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i=0; i<3; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int zero = 0, one = 0;
            
            while (st.hasMoreTokens()) {
                String s = st.nextToken();
                if (Integer.parseInt(s) == 0) {
                    zero++;
                }else {
                    one++;
                }
            }

            if (zero == 1 && one == 3)
                System.out.println("A");
            else if (zero == 2 && one == 2)
                System.out.println("B");
            else if (zero == 3 && one == 1)
                System.out.println("C");
            else if (zero == 4 && one == 0)
                System.out.println("D");
            else if (zero == 0 && one == 4)
                System.out.println("E");
        }
    }
}