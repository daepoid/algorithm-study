import java.util.HashSet;
import java.util.Set;

public class Q131701 {
    public static void main(String[] args) {
        Q131701 question = new Q131701();
        int[] elements = {7, 9, 1, 1, 4};
        int result = question.solution(elements);
        System.out.println("result = " + result);
    }

    public int solution(int[] elements) {
        Set<Integer> s = new HashSet<>();

        int[] sums = new int[elements.length * 2];
        sums[0] = elements[0];
        for (int i = 1; i < elements.length * 2; i++) {
            sums[i] = sums[i - 1] + elements[i % elements.length];
        }

        for (int i = 0; i < elements.length; i++) {
            for (int j = 1; j < elements.length + 1; j++) {
                s.add(sums[i + j] - sums[i]);
            }
        }

        return s.size();
    }
}
