import java.util.*;

public class Q132266 {
    public static void main(String[] args) {
//        int n = 3, destination = 1;
//        int[] sources = {2, 3};
//        int[][] roads = {{1, 2}, {2, 3}};

        int n = 5, destination = 5;
        int[] sources = {1, 3, 5};
        int[][] roads = {{1, 2}, {1, 4}, {2, 4}, {2, 5}, {4, 5}};

        Q132266 question = new Q132266();
        int[] result = question.solution(n, roads, sources, destination);
        for (int i : result) {
            System.out.println("i = " + i);
        }
    }

    void bfs(int destination, int[] answer, List<List<Integer>> board) {
        Queue<Integer> q = new LinkedList<>();
        q.add(destination);
        answer[destination] = 0;

        while (!q.isEmpty()) {
            int now = q.poll();

            for (int i = 0; i < board.get(now).size(); i++) {
                int next = board.get(now).get(i);
                if (answer[next] != -1) {
                    continue;
                }
                answer[next] = answer[now] + 1;
                q.add(next);
            }
        }
    }

    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        List<List<Integer>> board = new ArrayList<>();
        int[] dist = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            board.add(new ArrayList<>());
            dist[i] = -1;
        }
        for (int[] road : roads) {
            board.get(road[0]).add(road[1]);
            board.get(road[1]).add(road[0]);
        }
        bfs(destination, dist, board);
        return Arrays.stream(sources).map(i -> dist[i]).toArray();
    }
}
