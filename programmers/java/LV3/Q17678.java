import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Q17678 {
    public static void main(String[] args) {
        Q17678 question = new Q17678();
        int n = 2, t = 1, m = 2;
        String[] timetable = {"09:00", "09:00", "09:00", "09:00"};
        String result = question.solution(n, t, m, timetable);
        System.out.println("result = " + result);
    }

    String numToTime(int hour, int min) {
        return (hour < 10 ? "0" + hour : hour) + (min < 10 ? ":0" + min : ":" + min);
    }

    String getTimeString(int idx, int t) {
        int hour = 9 + idx * t / 60;
        int min = idx * t % 60;
        return numToTime(hour, min);
    }

    String oneMinuteBefore(String time) {
        int hour = Integer.parseInt(time.substring(0, 2));
        int min = Integer.parseInt(time.substring(3, 5)) - 1;
        return min < 0 ? numToTime(hour - 1, min += 60) : numToTime(hour, min);
    }

    public String solution(int n, int t, int m, String[] timetable) {

        String lastTime = getTimeString(n - 1, t);
        List<List<String>> board = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            board.add(new ArrayList<>());
        }
        timetable = Arrays.stream(timetable)
                .filter(time -> time.compareTo(lastTime) <= 0)
                .sorted()
                .toArray(String[]::new);

        if (timetable.length == 0) {
            return lastTime;
        }
        String answer = oneMinuteBefore(timetable[0]);

        int idx = 0;
        for (String time : timetable) {
            while (idx < n && time.compareTo(getTimeString(idx, t)) > 0) idx++;
            board.get(idx).add(time);
        }
        for (int i = 0; i < n; i++) {
            if (board.get(i).size() < m) answer = getTimeString(i, t);
            else {
                List<String> sublist = board.get(i).subList(m, board.get(i).size());
                board.get(i + 1).addAll(0, sublist);
                sublist.clear();
                answer = oneMinuteBefore(board.get(i).get(m - 1));
            }
        }

        return answer;
    }
}
