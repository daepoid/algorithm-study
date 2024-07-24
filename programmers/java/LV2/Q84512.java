import java.util.HashMap;
import java.util.Map;

public class Q84512 {
    Map<String, Integer> map = new HashMap<>();
    int val = 1;
    String[] s = {"A", "E", "I", "O", "U"};

    public static void main(String[] args) {
        Q84512 question = new Q84512();
        String word = "AAAAE";
        int result = question.solution(word);
        System.out.println("result = " + result);
    }

    void recursive(String str) {
        map.put(str, val++);
        if (str.length() == 5) {
            return;
        }

        for (int i = 0; i < 5; i++) {
            recursive(str + s[i]);
        }
    }

    public int solution(String word) {
        for (int i = 0; i < 5; i++) {
            recursive(s[i]);
        }
        return map.get(word);
    }
}
