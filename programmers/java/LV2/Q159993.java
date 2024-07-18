import java.util.LinkedList;
import java.util.Queue;

public class Q159993 {
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};

    public static void main(String[] args) {
        Q159993 question = new Q159993();
        String[] maps = {"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"};
        int answer = question.solution(maps);
        System.out.println("answer = " + answer);
    }

    boolean isValid(int newy, int newx, int N, int M) {
        return 0 <= newy && newy < N && 0 <= newx && newx < M;
    }

    int bfs(Pair s, Pair e, char ch, String[] maps) {
        Queue<Pair> q = new LinkedList<>();
        q.add(s);
        boolean[][] visited = new boolean[maps.length][maps[0].length()];
        visited[s.y][s.x] = true;
        while (!q.isEmpty()) {
            Pair now = q.poll();

            for (int i = 0; i < 4; i++) {
                int newy = now.y + dy[i];
                int newx = now.x + dx[i];
                int value = now.value;

                if (!isValid(newy, newx, maps.length, maps[0].length())) {
                    continue;
                }

                if (maps[newy].charAt(newx) == 'X') {
                    continue;
                }

                if (visited[newy][newx]) {
                    continue;
                }

                if (maps[newy].charAt(newx) == ch) {
                    return value + 1;
                } else {
                    visited[newy][newx] = true;
                    q.add(new Pair(newy, newx, value + 1));
                }
            }
        }
        return -1;
    }

    public int solution(String[] maps) {
        Pair s = null, l = null, e = null;
        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[0].length(); j++) {
                if (maps[i].charAt(j) == 'S') {
                    s = new Pair(i, j);
                } else if (maps[i].charAt(j) == 'L') {
                    l = new Pair(i, j);
                } else if (maps[i].charAt(j) == 'E') {
                    e = new Pair(i, j);
                }
            }
        }

        int s2l = bfs(s, l, 'L', maps);
        int l2e = bfs(l, e, 'E', maps);
        return ((s2l != -1 && l2e != -1) ? s2l + l2e : -1);
    }

    private class Pair {
        int y;
        int x;
        int value;

        public Pair(int y, int x) {
            this(y, x, 0);
        }

        public Pair(int y, int x, int value) {
            this.y = y;
            this.x = x;
            this.value = value;
        }
    }
}
