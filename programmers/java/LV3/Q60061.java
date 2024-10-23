import java.util.ArrayList;
import java.util.List;

public class Q60061 {
    public static void main(String[] args) {
        Q60061 question = new Q60061();
        int n = 5;
        int[][] build_frame = {{0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1}};
        int[][] result = question.solution(n, build_frame);
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[i].length; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }

    static final int PILLAR = 1;
    static final int BEAM = 2;

    boolean hasStructure(int y, int x, int[][] board, int pillarOrBeam) {
        return 0 <= y && y < board.length && 0 <= x && x < board.length && ((board[y][x] & pillarOrBeam) != 0);
    }

    boolean isWrong(int[][] board) {
        int n = board.length - 1;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if((board[i][j] & PILLAR) != 0 && i != 0 &&
                        !(hasStructure(i - 1, j, board, PILLAR) || hasStructure(i, j - 1, board, BEAM) || hasStructure(i, j, board, BEAM))
                ) return true;
                else if((board[i][j] & BEAM) != 0 &&
                        !(hasStructure(i - 1, j, board, PILLAR) || hasStructure(i - 1, j + 1, board, PILLAR) || (hasStructure(i, j - 1, board, BEAM) && hasStructure(i, j + 1, board, BEAM)))
                ) return true;
            }
        }
        return false;
    }

    int[][] toAnswerArray(int[][] board) {
        List<int[]> list = new ArrayList<>();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if ((board[i][j] & PILLAR) != 0) {
                    list.add(new int[]{j, i, 0});
                }
                if ((board[i][j] & BEAM) != 0) {
                    list.add(new int[]{j, i, 1});
                }
            }
        }
        return list.stream().sorted((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]).toArray(int[][]::new);
    }

    public int[][] solution(int n, int[][] build_frame) {
        int[][] board = new int[n + 1][n + 1];
        for (int[] frame : build_frame) {
            int x = frame[0], y = frame[1];
            boolean isPillar = (frame[2] == 0), isInstall = (frame[3] == 1);
            if(isInstall) {
                board[y][x] ^= (isPillar ? PILLAR : BEAM);
                if(isWrong(board)) {
                    board[y][x] &= (isPillar ? BEAM : PILLAR);
                }
            } else {
                board[y][x] &= (isPillar ? BEAM : PILLAR);
                if(isWrong(board)) {
                    board[y][x] ^= (isPillar ? PILLAR : BEAM);
                }
            }
        }

        return toAnswerArray(board);
    }
}
