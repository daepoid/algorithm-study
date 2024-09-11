import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Q9497 {

    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};
    int[][] answer;

    class Pair {
        int y;
        int x;
        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    boolean isValid(int newy, int newx, int N) {
        return 0 <= newy && newy < N && 0 <= newx && newx < N;
    }

    void bfs(int sy, int sx, int cnt, int[][] board) {
        int N = board.length;
        Queue<Pair> q = new LinkedList<>();
        boolean[] nums = new boolean[N + 1];
        q.add(new Pair(sy, sx));
        nums[board[sy][sx]] = true;
        answer[sy][sx] = cnt;

        while (!q.isEmpty()) {
            Pair now = q.poll();
            for (int i = 0; i < 4; i++) {
                int newy = now.y + dy[i];
                int newx = now.x + dx[i];

                if (!isValid(newy, newx, N)) {
                    continue;
                }

                if (nums[board[newy][newx]]) {
                    continue;
                }

                if (answer[newy][newx] != 0) {
                    continue;
                }

                nums[board[newy][newx]] = true;
                q.add(new Pair(newy, newx));
                answer[newy][newx] = cnt;
            }
        }
    }

    void print(int num, int[][] board) {
        System.out.println("=== num : " + num + " ===");
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                System.out.printf("%d ", board[i][j]);
            }
            System.out.println();
        }
    }

    void solution() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] board = new int[N][N];
        answer = new int[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = sc.nextInt();
            }
        }

        int cnt = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (answer[i][j] == 0) {
                    bfs(i, j, cnt, board);
                    print(cnt, answer);
                    cnt++;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j == N - 1) {
                    System.out.println(answer[i][j]);
                } else {
                    System.out.printf("%d ", answer[i][j]);
                }
            }
        }
    }

    public static void main(String[] args) {
        Q9497 question = new Q9497();
        question.solution();
    }
}
