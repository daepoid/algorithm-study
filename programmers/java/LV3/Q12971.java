public class Q12971 {
    public static void main(String[] args) {
        Q12971 question = new Q12971();
        int[] sticker = {14, 6, 5, 11, 3, 9, 2, 10};
        int result = question.solution(sticker);
        System.out.println("result = " + result);
    }

    public int solution(int[] sticker) {
        int[][] dp = new int[sticker.length + 1][2];
        if (sticker.length == 1) return sticker[0];
        dp[0][0] = dp[1][0] = sticker[0];
        dp[0][1] = 0;
        dp[1][1] = sticker[1];

        for (int i = 2; i < sticker.length; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 2][0] + sticker[i]);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 2][1] + sticker[i]);
        }
        return Math.max(dp[sticker.length - 2][0], dp[sticker.length - 1][1]);
    }
}
