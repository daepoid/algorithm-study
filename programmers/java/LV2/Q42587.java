import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Q42587 {
    public static void main(String[] args) {
        Q42587 question = new Q42587();
        int[] priorities = {2, 1, 3, 2};
        int location = 2;
        int result = question.solution(priorities, location);
        System.out.println("result = " + result);
    }

    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Integer> q = new LinkedList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int v : priorities) {
            q.add(v);
            pq.add(v);
        }

        while (!q.isEmpty()) {
            if (q.peek() == pq.peek()) {
                answer++;
                if (location == 0) {
                    return answer;
                }
                pq.poll();
            }

            int temp = q.peek();
            q.poll();
            q.add(temp);
            location--;
            if (location < 0) {
                location = q.size() - 1;
            }
        }
        return -1;
    }
}
