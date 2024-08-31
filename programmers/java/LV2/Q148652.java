import java.util.stream.LongStream;

public class Q148652 {
    public static void main(String[] args) {
        Q148652 question = new Q148652();
        int n = 2, l = 4, r = 17;
        int result = question.solution(n, l, r);
        System.out.println("result = " + result);
    }

    boolean check(long i) {
        if (i % 5 == 2) return false;
        if (i < 5) return true;
        return check(i / 5);
    }

    public int solution(int n, long l, long r) {
        return (int) LongStream.range(l - 1, r).filter(this::check).count();
    }
}
