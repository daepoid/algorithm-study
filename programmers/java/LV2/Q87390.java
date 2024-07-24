import java.util.stream.LongStream;

public class Q87390 {
    public static void main(String[] args) {
        Q87390 question = new Q87390();
        int n = 3;
        long left = 2, right = 5;
        int[] result = question.solution(n, left, right);
        for (int i : result) {
            System.out.println("i = " + i);
        }
    }

    public int[] solution(int n, long left, long right) {
        return LongStream.rangeClosed(left, right)
                .mapToInt(i -> (int) (Math.max(i / n, i % n)) + 1)
                .toArray();
    }
}
