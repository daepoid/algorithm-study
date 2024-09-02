import java.util.Arrays;

public class Q131130 {
    public static void main(String[] args) {
        Q131130 question = new Q131130();
        int[] cards = {8, 6, 3, 7, 2, 5, 1, 4};
        int result = question.solution(cards);
        System.out.println("result = " + result);
    }

    int selectGroup(int idx, int[] cards, boolean[] visited) {
        int cnt = 0;
        do {
            cnt++;
            visited[idx] = true;
            idx = cards[idx];
        } while (!visited[idx]);
        return cnt;
    }

    public int solution(int[] cards) {
        int maxVal = 0, minVal = 0;
        boolean[] visited = new boolean[cards.length];
        cards = Arrays.stream(cards).map(i -> i - 1).toArray();
        for (int i = 0; i < cards.length; i++) {
            if (visited[i]) continue;
            int val = selectGroup(i, cards, visited);

            if (val >= maxVal) {
                minVal = maxVal;
                maxVal = val;
            } else if (val > minVal) {
                minVal = val;
            }
        }

        return maxVal * minVal;
    }
}
