import java.util.HashMap;

public class Q17677 {
    public static void main(String[] args) {
        Q17677 question = new Q17677();
        String str1 = "FRANCE", str2 = "french";
        int result = question.solution(str1, str2);
        System.out.println("result = " + result);
    }

    public int solution(String str1, String str2) {
        final int VAL = 65536;

        HashMap<String, Integer> map1 = new HashMap<>();
        HashMap<String, Integer> map2 = new HashMap<>();

        for (int i = 0; i < str1.length() - 1; i++) {
            String substr = str1.substring(i, i + 2);
            if (substr.matches("^[a-zA-Z]{2}$")) {
                substr = substr.toLowerCase();
                map1.put(substr, map1.getOrDefault(substr, 0) + 1);
            }
        }

        for (int i = 0; i < str2.length() - 1; i++) {
            String substr = str2.substring(i, i + 2);
            if (substr.matches("^[a-zA-Z]{2}$")) {
                substr = substr.toLowerCase();
                map2.put(substr, map2.getOrDefault(substr, 0) + 1);
            }
        }

        int sum = 0;
        int total = 0;

        for (String key : map1.keySet()) {
            sum += Math.min(map1.get(key), map2.getOrDefault(key, 0));
            total += Math.max(map1.get(key), map2.getOrDefault(key, 0));
        }

        for (String key : map2.keySet()) {
            total += map1.getOrDefault(key, 0) == 0 ? map2.get(key) : 0;
        }
        return (int) ((total == 0 ? 1 : sum / (double) total) * VAL);
    }
}
