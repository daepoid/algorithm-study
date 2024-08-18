import java.util.stream.IntStream;

public class Q140107 {
    public static void main(String[] args) {
        Q140107 question = new Q140107();
        int k = 2, d = 4;
//        int k = 1, d = 1;
        long result = question.solution(k, d);
        System.out.println("result = " + result);
    }

    public long solution(int k, int d) {
        return IntStream.rangeClosed(0, d / k)
                .mapToDouble(i -> i * k)
                .mapToLong(i -> (long) Math.sqrt((double) d * d - i * i) / k + 1)
                .sum();
    }
}
