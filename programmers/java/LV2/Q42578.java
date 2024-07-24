import java.util.HashMap;

public class Q42578 {
    public static void main(String[] args) {
        Q42578 question = new Q42578();
        String[][] clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
        int result = question.solution(clothes);
        System.out.println("result = " + result);
    }

    public int solution(String[][] clothes) {
        HashMap<String, Integer> map = new HashMap<>();
        for (String[] e : clothes) {
            map.put(e[1], map.getOrDefault(e[1], 0) + 1);
        }

        int answer = 1;
        for (String s : map.keySet()) {
            answer *= (map.get(s) + 1);
        }

        return answer - 1;
    }
}
