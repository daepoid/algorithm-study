import java.util.HashMap;
import java.util.Map;

public class Q17680 {
    public static void main(String[] args) {
        Q17680 question = new Q17680();
        int cacheSize = 3;
        String[] cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
        int result = question.solution(cacheSize, cities);
        System.out.println("result = " + result);
    }

    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        Map<String, Integer> cache = new HashMap<>();

        for (int i = 0; i < cities.length; i++) {
            String newName = cities[i].toLowerCase();
            if (cache.containsKey(newName)) {
                cache.put(newName, i);
                answer += 1;
            } else {
                answer += 5;
                cache.put(newName, i);
            }

            while (cacheSize < cache.size()) {
                String str = "";
                int maxVal = cities.length + 1;
                for (Map.Entry<String, Integer> entry : cache.entrySet()) {
                    if (entry.getValue() < maxVal) {
                        maxVal = entry.getValue();
                        str = entry.getKey();
                    }
                }
                cache.remove(str);
            }
        }

        return answer;
    }
}
