/*
    2022.05.05
    PGM : 42888 오픈채팅방 (https://programmers.co.kr/learn/courses/30/lessons/42888)
    Algorithm : 구현
*/
import java.util.ArrayList;
import java.util.HashMap;

class Solution {
  public String[] solution(String[] record) {
    HashMap<String, String> db = new HashMap<>();
    ArrayList<Log> log = new ArrayList<>();

    for (String data : record) {
      String[] split = data.split(" ");

      String command = split[0];
      String uid = split[1];
      if (!command.equals("Leave")) {
        String nickname = split[2];
        db.put(uid, nickname);
      }

      log.add(new Log(uid, command));
    }

    ArrayList<String> answer = new ArrayList<>();
    for (Log l : log) {
      if (l.command.equals("Change")) continue;

      String s = null;
      if (l.command.equals("Enter")) {
        s = db.get(l.uid) + "님이 들어왔습니다.";
      } else {
        s = db.get(l.uid) + "님이 나갔습니다.";
      }

      answer.add(s);
    }

    return answer.toArray(String[]::new);
  }

  public static class Log {
    String uid;
    String command;

    public Log(String uid, String command) {
      this.uid = uid;
      this.command = command;
    }
  }
}