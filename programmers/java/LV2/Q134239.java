import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Q134239 {

    public static void main(String[] args) {
        Q134239 question = new Q134239();
        int k = 5;
        int[][] ranges = {{0, 0}, {0, -1}, {2, -3}, {3, -3}};
        double[] result = question.solution(k, ranges);
        for (double v : result) {
            System.out.println("v = " + v);
        }
    }

    List<Double> calculate(int start) {
        List<Integer> result = new ArrayList<>();
        while (start > 1) {
            result.add(start);
            if (start % 2 == 0) {
                start /= 2;
            } else {
                start = start * 3 + 1;
            }
        }
        result.add(start);

        List<Double> sums = new ArrayList<>();
        sums.add(0.0);
        for (int i = 0; i < result.size() - 1; i++) {
            sums.add(sums.get(i) + Math.min(result.get(i), result.get(i + 1)) + (double) Math.abs(result.get(i) - result.get(i + 1)) / 2);
        }
        return sums;
    }

    public double[] solution(int k, int[][] ranges) {
        List<Double> list = calculate(k);
        int N = list.size() - 1;
        return Arrays.stream(ranges)
                .mapToDouble(array -> N + array[1] < array[0] ? -1.0 : list.get(N + array[1]) - list.get(array[0]))
                .toArray();
    }
}
