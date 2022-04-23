/*
	2022.04.23
	BOJ : 10825 국영수 (https://www.acmicpc.net/problem/10825)
	Algorithm : 정렬
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ10825 {
    static int N;
    static ArrayList<Student> students = new ArrayList<>();

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            students.add(new Student(st.nextToken(), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
    }
    public static void main(String[] args) throws IOException {
        input();

        Collections.sort(students);

        StringBuilder sb = new StringBuilder();
        for (Student s : students) {
            sb.append(s.name).append("\n");
        }

        System.out.println(sb.toString());
    }

    public static class Student implements Comparable<Student> {
        String name;
        int kor;
        int eng;
        int math;

        public Student(String n, int k, int e, int m) {
            this.name = n;
            this.kor = k;
            this.eng = e;
            this.math = m;
        }

        @Override
        public int compareTo(Student st) {
            // 국어 점수 기준 내림차순
            // 영어점수 기준 오름차순
            // 수학점수 기준 내림차순
            // 이름 기준 오름차순
            if (kor == st.kor) {
                if (eng == st.eng) {
                    if (math == st.math) {
                        return name.compareTo(st.name);
                    }
                    return st.math - math;
                }
                return eng - st.eng;
            }
            return st.kor - kor;
        }
    }
}