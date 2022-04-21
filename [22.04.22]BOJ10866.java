/*
	2022.04.22
	BOJ : 10866 덱 (https://www.acmicpc.net/problem/10866)
	Algorithm : 자료구조
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ10866 {
    public static void main(String[] args) throws IOException {
        Deque deque = new Deque();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (int i=0; i<N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();
            int x;

            if (command.equals("push_back")) {
                x = Integer.parseInt(st.nextToken());
                deque.push_back(x);
            } else if (command.equals("push_front")) {
                x = Integer.parseInt(st.nextToken());
                deque.push_front(x);
            } else if (command.equals("pop_front")) {
                System.out.println(deque.pop_front());
            } else if (command.equals("pop_back")) {
                System.out.println(deque.pop_back());
            } else if (command.equals("size")) {
                System.out.println(deque.size());
            } else if (command.equals("empty")) {
                System.out.println(deque.empty());
            } else if (command.equals("front")) {
                System.out.println(deque.front());
            } else if (command.equals("back")) {
                System.out.println(deque.back());
            }
        }
    }

    public static class Deque {
        private LinkedList<Integer> data = new LinkedList<>();

        void push_front(int x) {
            data.addFirst(x);
        }

        void push_back(int x) {
            data.addLast(x);
        }

        int pop_front() {
            if (data.isEmpty()) return -1;

            return data.removeFirst();
        }

        int pop_back() {
            if (data.isEmpty()) return -1;

            return data.removeLast();
        }

        int size() {
            return data.size();
        }

        int empty() {
            return data.isEmpty() ? 1 : 0;
        }

        int front() {
            if (data.isEmpty()) return -1;
            return data.peekFirst();
        }

        int back() {
            if (data.isEmpty()) return -1;
            return data.peekLast();
        }
    }
}
