public class Q77485 {
    int[][] board;

    public static void main(String[] args) {
        Q77485 question = new Q77485();
        int rows = 6, columns = 6;
        int[][] queries = {{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}};
        int[] result = question.solution(rows, columns, queries);
        for (int i : result) {
            System.out.println("i = " + i);
        }

    }

    public int rotateBoard(int r1, int c1, int r2, int c2) {
        int minVal = 2100000000;
        int temp = board[r1][c1];

        // 좌측
        for (int i = r1; i < r2; i++) {
            board[i][c1] = board[i + 1][c1];
            minVal = Math.min(minVal, board[i + 1][c1]);
        }

        // 하단
        for (int i = c1; i < c2; i++) {
            board[r2][i] = board[r2][i + 1];
            minVal = Math.min(minVal, board[r2][i + 1]);
        }

        // 우측
        for (int i = r2; i > r1; i--) {
            board[i][c2] = board[i - 1][c2];
            minVal = Math.min(minVal, board[i - 1][c2]);
        }

        // 상단
        for (int i = c2; i > c1; i--) {
            board[r1][i] = board[r1][i - 1];
            minVal = Math.min(minVal, board[r1][i - 1]);
        }

        board[r1][c1 + 1] = temp;
        minVal = Math.min(minVal, temp);
        return minVal;
    }

    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        board = new int[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                board[i][j] = i * columns + j + 1;
            }
        }
        for (int i = 0; i < queries.length; i++) {
            answer[i] = rotateBoard(queries[i][0] - 1, queries[i][1] - 1, queries[i][2] - 1, queries[i][3] - 1);
        }
        return answer;
    }
}
