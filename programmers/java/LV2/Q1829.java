import java.util.LinkedList;
import java.util.Queue;

public class Q1829 {
    class Pair {
        int y, x;
        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    int[] dy = { 0, 1, 0, -1 };
    int[] dx = { 1, 0, -1, 0 };

    boolean isValid(int newy, int newx, int M, int N) {
        return 0 <= newy && newy < M && 0 <= newx && newx < N;
    }

    int bfs(int sy, int sx, boolean[][] visited, int[][] board) {
        int color = board[sy][sx];
        int cnt = 1;
        visited[sy][sx] = true;
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(sy, sx));
        while(!q.isEmpty()) {
            Pair now = q.poll();
            for (int i = 0; i < 4; i++) {
                int newy = now.y + dy[i];
                int newx = now.x + dx[i];

                if (!isValid(newy, newx, board.length, board[0].length)) {
                    continue;
                }

                if (board[newy][newx] != color) {
                    continue;
                }

                if (visited[newy][newx]) {
                    continue;
                }
                q.offer(new Pair(newy, newx));
                visited[newy][newx] = true;
                cnt++;
            }
        }
        return cnt;
    }

    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        boolean [][] visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && picture[i][j] != 0) {
                    int sz = bfs(i, j, visited, picture);
                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea, sz);
                    numberOfArea++;
                }
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }

    public static void main(String[] args) {
        Q1829 question = new Q1829();
        int m = 6;
        int n = 4;
        int[][] picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
        int[] result = question.solution(m, n, picture);
        System.out.println("result[0] = " + result[0]);
        System.out.println("result[1] = " + result[1]);
    }
}
