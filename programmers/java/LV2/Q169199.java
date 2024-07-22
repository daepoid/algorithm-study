import java.util.LinkedList;
import java.util.Queue;

public class Q169199 {
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};

    public static void main(String[] args) {
        Q169199 question = new Q169199();
        String[] board = {"...D..R", ".D.G...", "....D.D", "D....D.", "..D...."};
        int result = question.solution(board);
        System.out.println("result = " + result);
    }

    boolean isValid(int newy, int newx, int N, int M) {
        return 0 <= newy && newy < N && 0 <= newx && newx < M;
    }

    int bfs(Pair R, String[] board) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(R.y, R.x));
        boolean[][] visited = new boolean[board.length][board[0].length()];
        visited[R.y][R.x] = true;

        while (!q.isEmpty()) {
            Pair now = q.poll();

            for (int i = 0; i < 4; i++) {
                int newy = now.y;
                int newx = now.x;
                while (true) {
                    if (!isValid(newy + dy[i], newx + dx[i], board.length, board[0].length())) {
                        break;
                    }
                    if (board[newy + dy[i]].charAt(newx + dx[i]) == 'D') {
                        break;
                    }
                    newy += dy[i];
                    newx += dx[i];
                }

                if (visited[newy][newx]) {
                    continue;
                }

                if (board[newy].charAt(newx) == 'G') {
                    return now.cnt + 1;
                } else {
                    visited[newy][newx] = true;
                    q.add(new Pair(newy, newx, now.cnt + 1));
                }
            }
        }
        return -1;
    }

    public int solution(String[] board) {
        Pair R, G;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length(); j++) {
                if (board[i].charAt(j) == 'R') {
                    R = new Pair(i, j);
                    return bfs(R, board);
                }
            }
        }
        return -1;
    }

    private class Pair {
        int y;
        int x;
        int cnt;

        public Pair(int y, int x) {
            this(y, x, 0);
        }

        public Pair(int y, int x, int cnt) {
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }
    }
}
