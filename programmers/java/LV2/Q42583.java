import java.util.ArrayDeque;
import java.util.Deque;

public class Q42583 {
    public static void main(String[] args) {
        Q42583 question = new Q42583();
        int bridge_length = 2, weight = 4;
        int[] truck_weights = {7, 4, 5, 6};
        int result = question.solution(bridge_length, weight, truck_weights);
        System.out.println("result = " + result);
    }

    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0, sum = 0;
        Deque<Integer> bridge = new ArrayDeque<>();

        for (int i = 0; i < truck_weights.length; i++) {
            int truck = truck_weights[i];
            while (true) {
                answer++;
                if (bridge.isEmpty()) {
                    bridge.offerLast(truck);
                    sum += truck;
                    break;
                } else if (bridge.size() == bridge_length) {
                    sum -= bridge.peekFirst();
                    bridge.poll();
                    answer--;
                } else {
                    if (sum + truck > weight) {
                        bridge.offerLast(0);
                    } else {
                        bridge.offerLast(truck);
                        sum += truck;
                        break;
                    }

                }
            }
        }
        return answer + bridge_length;
    }
}
