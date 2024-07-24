import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Q138476 {
    public static void main(String[] args) {
        Q138476 question = new Q138476();
        int k = 6;
        int[] tangerine = {1, 3, 2, 5, 4, 5, 2, 3};
        int result = question.solution(k, tangerine);
        System.out.println("result = " + result);
    }

    public int solution(int k, int[] tangerine) {
        int answer = 0;
        Map<Integer, Integer> map = new HashMap<>();

        for (int v : tangerine) {
            map.put(v, map.getOrDefault(v, 0) + 1);
        }

        List<Map.Entry<Integer, Integer>> entryList = new ArrayList<>(map.entrySet());
        entryList.sort((o1, o2) -> o2.getValue() - o1.getValue());

        for (Map.Entry<Integer, Integer> entry : entryList) {
            if (k <= 0) {
                break;
            }
            k -= entry.getValue();
            answer++;
        }

        return answer;
    }
}
