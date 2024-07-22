import java.util.Collections;
import java.util.PriorityQueue;

public class Q142085 {
    public static void main(String[] args) {
//        int n = 7, k = 3;
//        int[] enemy = {4, 2, 4, 5, 3, 3, 1};
        int n = 2, k = 4;
        int[] enemy = {3, 3, 3, 3};
        Q142085 question = new Q142085();
        int result = question.solution(n, k, enemy);
        System.out.println("result = " + result);
    }

    public int solution(int n, int k, int[] enemy) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < enemy.length; i++) {
            pq.add(enemy[i]);
            n -= enemy[i];
            if (n < 0 && k > 0) {
                while (!pq.isEmpty() && k > 0 && n <= 0) {
                    n += pq.poll();
                    k--;
                }
            }
            if (n < 0) return i;
        }
        return enemy.length;
    }
}
