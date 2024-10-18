import java.util.HashMap;
import java.util.Map;

public class Q1835 {
    String[] friends = {"A", "C", "F", "J", "M", "N", "R", "T"};
    int answer = 0;

    public static void main(String[] args) {
        Q1835 question = new Q1835();

        int n = 2;
        String[] data = {"N~F=0", "R~T>2"};
        int result = question.solution(n, data);
        System.out.println("result = " + result);
    }

    boolean isValid(String now, String[] data) {
        Map<String, Integer> map = new HashMap<>();
        int idx = 0;
        for (char ch : now.toCharArray()) {
            map.put(String.valueOf(ch), idx++);
        }

        for (String cond : data) {
            int diff = Math.abs(map.get(cond.substring(0, 1)) - map.get(cond.substring(2, 3))) - 1;
            char ch = cond.charAt(3);
            int val = cond.charAt(4) - '0';
            if (ch == '<' && diff >= val) {
                return false;
            } else if (ch == '>' && diff <= val) {
                return false;
            } else if (ch == '=' && diff != val) {
                return false;
            }
        }
        return true;
    }

    void brute(int visited, String now, String[] data) {
        if (visited == Math.pow(2, 8) - 1) {
            answer += isValid(now, data) ? 1: 0;
            return ;
        }

        for (int i = 0; i < friends.length; i++) {
            if ((visited & (1 << i)) == 0) {
                brute(visited | (1 << i), now + friends[i], data);
            }
        }
    }


    public int solution(int n, String[] data) {
        for (int i = 0; i < friends.length; i++) {
            int visited = 1 << i;
            brute(visited, friends[i], data);
        }
        return answer;
    }
}
