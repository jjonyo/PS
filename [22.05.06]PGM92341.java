/*
    2022.05.06
    PGM : 92341 주차 요금 게산 (https://programmers.co.kr/learn/courses/30/lessons/92341)
    Algorithm : 문자열, 구현
*/
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

class Solution {

  static List<CarInfo> carList = new LinkedList<>();
  static Map<String, Queue<String>> log = new HashMap<>();
  static SimpleDateFormat dateFormat = new SimpleDateFormat("HH:mm");

  public int[] solution(int[] fees, String[] records) throws ParseException {
    for (String record : records) {
      String[] split = record.split(" ");
      String carNumber = split[1];

      if (log.containsKey(carNumber)) {
        log.get(carNumber).add(record);
      } else {
        Queue<String> logString = new LinkedList<>();
        logString.add(record);
        log.put(carNumber, logString);
        carList.add(new CarInfo(carNumber, 0, 0));
      }
    }

    for (CarInfo carInfo : carList) {
      String carNumber = carInfo.carNumber;

      Queue<String> logList = log.get(carNumber);
      while (!logList.isEmpty()) {
        String currentTime;
        String nextTime;

        currentTime = logList.poll().split(" ")[0];
        if (!logList.isEmpty()) {
          nextTime = logList.poll().split(" ")[0];
        } else {
          nextTime = "23:59";
        }

        long diff = dateFormat.parse(nextTime).getTime() - dateFormat.parse(currentTime).getTime();
        long minute = diff / 60000;

        carInfo.time += minute;
      }
    }

    int defaultMinute = fees[0];
    int defaultFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];

    for(CarInfo carInfo : carList) {
      if (carInfo.time <= defaultMinute) {
        carInfo.fee = defaultFee;
      }
      else {
        carInfo.fee = defaultFee
            + (int) Math.ceil((double) (carInfo.time - defaultMinute) / unitTime) * unitFee;
      }
    }

    Collections.sort(carList);

    return carList.stream().mapToInt(carInfo -> carInfo.fee).toArray();
  }

  public static class CarInfo implements Comparable<CarInfo> {

    String carNumber;
    int time;
    int fee;

    public CarInfo(String carNumber, int time, int fee) {
      this.carNumber = carNumber;
      this.time = time;
      this.fee = fee;
    }

    @Override
    public int compareTo(CarInfo o) {
      return this.carNumber.compareTo(o.carNumber);
    }
  }
}
