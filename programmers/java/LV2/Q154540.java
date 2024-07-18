import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Q154540 {

    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};

    public static void main(String[] args) {
        Q154540 question = new Q154540();
        String[] maps = {"X591X", "X1X5X", "X231X", "1XXX1"};
        int[] solution = question.solution(maps);
        for (int sol : solution) {
            System.out.print(sol + " ");
        }
        System.out.println();
    }

    public boolean isValid(int newY, int newX, int N, int M) {
        return 0 <= newY && newY < N && 0 <= newX && newX < M;
    }

    public int bfs(int a, int b, String[] maps, boolean[][] visited) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(a, b));
        visited[a][b] = true;
        int tempSum = (int) (maps[a].charAt(b) - '0');
        while (!q.isEmpty()) {
            Pair pair = q.poll();

            for (int i = 0; i < 4; i++) {
                int newy = pair.y + dy[i];
                int newx = pair.x + dx[i];

                if (!isValid(newy, newx, maps.length, maps[0].length())) {
                    continue;
                }

                if (maps[newy].charAt(newx) == 'X') {
                    continue;
                }

                if (visited[newy][newx]) {
                    continue;
                }

                tempSum += (int) (maps[newy].charAt(newx) - '0');
                visited[newy][newx] = true;
                q.add(new Pair(newy, newx));
            }
        }
        return tempSum;
    }

    public int[] solution(String[] maps) {
        List<Integer> answer = new ArrayList<>();
        boolean[][] visited = new boolean[maps.length + 1][maps[0].length() + 1];

        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                if (maps[i].charAt(j) != 'X' && !visited[i][j]) {
                    int val = bfs(i, j, maps, visited);
                    answer.add(val);
                }
            }
        }

        if (answer.isEmpty()) {
            answer.add(-1);
        }
        return answer.stream().sorted().mapToInt(Integer::intValue).toArray();
    }

    private class Pair {
        int y;
        int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
