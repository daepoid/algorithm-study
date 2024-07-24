import java.util.HashMap;
import java.util.Map;

public class Q131127 {
    public static void main(String[] args) {
        Q131127 question = new Q131127();
        String[] want = {"banana", "apple", "rice", "pork", "pot"};
        int[] number = {3, 2, 2, 2, 1};
        String[] discount = {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"};
        int result = question.solution(want, number, discount);
        System.out.println("result = " + result);
    }

    public boolean compareMap(Map<String, Integer> origin, Map<String, Integer> temp) {
        if (origin.size() != temp.size()) {
            return false;
        }

        for (Map.Entry<String, Integer> entry : origin.entrySet()) {
            if (entry.getValue() != temp.getOrDefault(entry.getKey(), -1)) {
                return false;
            }
        }
        return true;
    }

    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        Map<String, Integer> map = new HashMap<>();
        Map<String, Integer> temp = new HashMap<>();
        for (int i = 0; i < want.length; i++) {
            map.put(want[i], number[i]);
        }

        for (int i = 0; i < 9; i++) {
            temp.put(discount[i], temp.getOrDefault(discount[i], 0) + 1);
        }

        for (int i = 0; i + 9 < discount.length; i++) {
            int next = i + 9;
            temp.put(discount[next], temp.getOrDefault(discount[next], 0) + 1);
            if (compareMap(map, temp)) {
                answer++;
            }
            temp.put(discount[i], temp.getOrDefault(discount[i], 0) - 1);
            if (temp.get(discount[i]) <= 0) {
                temp.remove(discount[i]);
            }
        }
        return answer;
    }
}
