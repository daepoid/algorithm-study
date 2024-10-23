import java.util.Arrays;

public class Q72413 {

    public static void main(String[] args) {
        Q72413 question = new Q72413();
        int n = 6;
        int s = 4;
        int a = 6;
        int b = 2;
        int[][] fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
        int result = question.solution(n, s, a, b, fares);
        System.out.println("result = " + result);
    }

    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = 0;
        final int INF = Integer.MAX_VALUE;
        int[][] board = new int[n + 1][n + 1];
        for (int i = 0; i < n + 1; i++) {
            Arrays.fill(board[i], INF);
        }

        return answer;
    }
}
