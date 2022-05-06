/*
    2022.05.06
    PGM : 42891 무지의 먹방 라이브(정확성) (https://programmers.co.kr/learn/courses/30/lessons/42891)
    Algorithm : 자료구조
*/

import java.util.ArrayList;

class Solution {

  public int solution(int[] food_times, long k) {
    ArrayList<Node> list = new ArrayList<>();
    for (int i=0; i<food_times.length; i++) {
      list.add(new Node(food_times[i], i + 1));
    }

    for (int i=0; i<list.size(); i++) {
      Node node = list.get(i);
      Node nextNode;
      if (i == list.size() - 1) {
        nextNode = list.get(0);
      } else {
        nextNode = list.get(i + 1);
      }

      node.next = nextNode;
      nextNode.prev = node;
    }

    Node currentNode = list.get(0);
    int cnt = 0;
    while(cnt < k) {
      currentNode.value -= 1;
      if (currentNode.value == 0) {
        currentNode.prev.next = currentNode.next;
        currentNode.next.prev = currentNode.prev;
      }

      if (currentNode.next.equals(currentNode)) {
        //자기 자신만 남았을 경우
        //K값 차감해줘야하고 멈추기
        currentNode.value -= (k - cnt - 1);
        break;

      }
      cnt++;
      currentNode = currentNode.next;
    }

    if (currentNode.value > 0) {
      return currentNode.index;
    } else {
      return -1;
    }
  }

  public static class Node {
    int value;
    int index;
    Node prev;
    Node next;

    public Node(int value, int index) {
      this.value = value;
      this.index = index;
    }
  }
}
