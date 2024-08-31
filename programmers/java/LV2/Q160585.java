import java.util.Arrays;

public class Q160585 {
    public static void main(String[] args) {
        Q160585 question = new Q160585();
        String[] board = {"OOO", "...", "XXX"};
        int result = question.solution(board);
        System.out.println("result = " + result);
    }

    public int isWin(char[][] board) {
        int result = 0; // O win -> 2, X win -> 1
        for (int i = 0; i < board.length; i++) {
            int rowCnt = 0, colCnt = 0;
            for (int j = 0; j < board[i].length; j++) {
                rowCnt += (board[i][j] == 'O' ? 1 : (board[i][j] == 'X' ? -1 : 0));
                colCnt += (board[j][i] == 'O' ? 1 : (board[j][i] == 'X' ? -1 : 0));
            }
            result += (rowCnt == 3 || colCnt == 3 ? 2 : 0);
            result += (rowCnt == -3 || colCnt == -3 ? 1 : 0);
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            result += (board[1][1] == 'O' ? 2 : (board[1][1] == 'X' ? 1 : 0));
        } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            result += (board[1][1] == 'O' ? 2 : (board[1][1] == 'X' ? 1 : 0));
        }

        return result;
    }

    public int solution(String[] board) {
        int answer = 0;
        int o = 0, x = 0;
        char[][] boards = Arrays.stream(board).map(String::toCharArray).toArray(char[][]::new);
        for (int i = 0; i < 3; i++) {
            int rowO = 0, rowX = 0;
            for (int j = 0; j < 3; j++) {
                switch (board[i].charAt(j)) {
                    case 'O' -> o++;
                    case 'X' -> x++;
                }
            }
        }

        int result = isWin(boards);
        if (o == x) {
            answer = (result <= 1 ? 1 : 0);
        } else if (o == x + 1) {
            answer = (result % 2 == 0 ? 1 : 0);
        }
        return answer;
    }
}
