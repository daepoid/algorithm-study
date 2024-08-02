public class Q12902 {
    public static void main(String[] args) {
        Q12902 question = new Q12902();
        int n = 4;
        int result = question.solution(n);
        System.out.println("result = " + result);
    }

    public int solution(int n) {
        long[] dp = new long[n + 1];
        long MOD = 1000000007;
        dp[0] = 1;
        dp[2] = 3;

        for (int i = 4; i <= n; i++) {
            dp[i] = (MOD + 4 * dp[i - 2] - dp[i - 4]) % MOD;
        }
        return (int) dp[n];
    }
}
