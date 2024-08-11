import java.math.BigInteger;

public class Q62048 {
    public static void main(String[] args) {
        Q62048 question = new Q62048();
        int W = 8, H = 12;
        long result = question.solution(W, H);
        System.out.println("result = " + result);
    }

    public long solution(int w, int h) {
        return (long) w * h - (w + h - BigInteger.valueOf(w).gcd(BigInteger.valueOf(h)).longValue());
    }
}
