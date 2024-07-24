import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Q17684 {
    public static void main(String[] args) {
        Q17684 question = new Q17684();
        String msg = "KAKAO";
        question.solution(msg);
    }

    public int[] solution(String msg) {
        HashMap<String, Integer> map = new HashMap<>();
        List<Integer> arr = new ArrayList<>();

        for (int i = 0; i < 26; i++) {
            map.put(String.valueOf((char) ('A' + i)), i + 1);
        }

        for (int i = 0; i < msg.length(); i++) {
            for (int j = i; j <= msg.length(); j++) {
                String temp;
                if (j + 1 > msg.length()) {
                    temp = msg.substring(i, j);
                    arr.add(map.get(temp));
                    i = j - 1;
                    break;
                }

                temp = msg.substring(i, j + 1);
                if (map.getOrDefault(temp, -1) == -1) {
                    arr.add(map.get(msg.substring(i, j)));
                    map.put(temp, map.size() + 1);
                    i = j - 1;
                    break;
                }
            }
        }
        return arr.stream().mapToInt(i -> i).toArray();
    }
}
