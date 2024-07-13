import java.util.LinkedList;
import java.util.Queue;

class Q86971 {

    public int bfs(boolean[][] board, int n) {
        boolean[] visited = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        int cnt = 0;
        while(!q.isEmpty()) {
            int now = q.poll();

            for(int i = 1; i < n + 1; i++) {
                if(board[now][i] && !visited[i]) {
                    visited[i] = true;
                    cnt++;
                    q.add(i);
                }
            }
        }
        return cnt;
    }

    public int solution(int n, int[][] wires) {
        int answer = n;
        boolean[][] board = new boolean[n + 1][n + 1];
        for(int[] wire : wires) {
            board[wire[0]][wire[1]] = true;
            board[wire[1]][wire[0]] = true;
        }
        for(int[] wire : wires) {
            board[wire[0]][wire[1]] = false;
            board[wire[1]][wire[0]] = false;
            int val = bfs(board, n);
            answer = Math.min(answer, Math.abs(n - 2 * val));
            board[wire[0]][wire[1]] = true;
            board[wire[1]][wire[0]] = true;
        }
        return answer;
    }

    public static void main(String[] args) {
        Q86971 question = new Q86971();
        int n = 9;
        int[][] wires = {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}};
        int answer = question.solution(n, wires);
        System.out.println("answer = " + answer);
    }
}