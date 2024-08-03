public class Q161988 {

    public static void main(String[] args) {
        Q161988 question = new Q161988();
        int[] sequence = {2, 3, -6, 1, 3, -1, 2, 4};
        long result = question.solution(sequence);
        System.out.println("result = " + result);
    }

    public long solution(int[] sequence) {
        long answer = 0;
        long[][] dp = new long[sequence.length][2];
        dp[0][0] = sequence[0];
        dp[0][1] = sequence[0] * -1;
        answer = Math.max(dp[0][0], dp[0][1]);
        for (int i = 1; i < sequence.length; i++) {
            int value = (i % 2 == 0 ? sequence[i] : -sequence[i]);
            dp[i][0] = Math.max(dp[i - 1][0] + value, value);
            dp[i][1] = Math.max(dp[i - 1][1] - value, -value);
            answer = Math.max(answer, dp[i][0]);
            answer = Math.max(answer, dp[i][1]);
        }
        return answer;
    }
}
