import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

public class Q42586 {
    public static void main(String[] args) {
        Q42586 question = new Q42586();
        int[] progresses = {93, 30, 55};
        int[] speeds = {1, 30, 5};
        int[] result = question.solution(progresses, speeds);
        for (int i : result) {
            System.out.println("i = " + i);
        }
    }

    public int[] solution(int[] progresses, int[] speeds) {
        int[] times = IntStream.range(0, progresses.length)
                .map(i -> (100 - progresses[i] - 1) / speeds[i] + 1)
                .toArray();

        List<Integer> answer = new ArrayList<>();
        int temp = times[0];
        int cnt = 1;
        for (int i = 1; i < times.length; i++) {
            if (temp >= times[i]) {
                cnt++;
            } else {
                answer.add(cnt);
                temp = times[i];
                cnt = 1;
            }
        }
        answer.add(cnt);

        return answer.stream().mapToInt(i -> i).toArray();
    }
}
