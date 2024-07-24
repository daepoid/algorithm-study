import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class Q92341 {
    public static void main(String[] args) {
        Q92341 question = new Q92341();
        int[] fees = {};
        String[] records = {};
        int[] result = question.solution(fees, records);
        for (int i : result) {
            System.out.println("i = " + i);
        }
    }

    public int calculateTime(String strTime) {
        String[] split = strTime.split(":");
        return Integer.parseInt(split[0]) * 60 + Integer.parseInt(split[1]);
    }

    public int calculateCost(int time, int[] fees) {
        if (time <= fees[0]) {
            return fees[1];
        } else {
            return fees[1] + (int) Math.ceil((time - fees[0]) / (double) fees[2]) * fees[3];
        }
    }

    public int[] solution(int[] fees, String[] records) {
        HashMap<String, Integer> map = new HashMap<>();
        HashSet<String> sets = new HashSet<>();
        for (String record : records) {
            String[] splits = record.split(" ");
            int time = splits[2].equals("IN") ? -1 : 1;
            time *= calculateTime(splits[0]);
            map.put(splits[1], map.getOrDefault(splits[1], 0) + time);
        }

        for (String key : map.keySet()) {
            if (map.get(key) <= 0) {
                map.put(key, map.get(key) + calculateTime("23:59"));
            }
        }

        return map.entrySet().stream()
                .sorted(Map.Entry.comparingByKey())
                .mapToInt(e -> calculateCost(e.getValue(), fees))
                .toArray();
    }
}
