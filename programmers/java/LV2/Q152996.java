import java.util.HashMap;
import java.util.Map;

public class Q152996 {
    public static void main(String[] args) {
        Q152996 question = new Q152996();
        int[] weights = {100, 180, 360, 100, 270};
        long answer = question.solution(weights);
        System.out.println("answer = " + answer);
    }

    public long solution(int[] weights) {
        long answer = 0;
        Map<Integer, Long> m = new HashMap<>();
        for (int weight : weights) {
            m.put(weight, m.getOrDefault(weight, 0L) + 1);
        }
        for (Integer weight : m.keySet()) {
            long cnt = m.get(weight);
            answer += (cnt * (cnt - 1)) / 2;
            answer += (cnt * m.getOrDefault(weight * 2, 0L));
            if (weight % 2 == 0) {
                answer += (cnt * m.getOrDefault(weight / 2 * 3, 0L));
            }
            if (weight % 3 == 0) {
                answer += (cnt * m.getOrDefault(weight / 3 * 4, 0L));
            }
        }
        return answer;
    }
}
