import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Q87377 {

    public static void main(String[] args) {
        Q87377 question = new Q87377();
        int[][] line = {{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}};
        String[] result = question.solution(line);
        for (String s : result) {
            System.out.println(s);
        }
    }

    public String[] solution(int[][] line) {
        long szl = 100000L * 100000 * 2, szr = -szl, szu = -szl, szd = szl;
        List<Long[]> list = new ArrayList<>();
        for (int i = 0; i < line.length; i++) {
            for (int j = i + 1; j < line.length; j++) {
                long a = line[i][0], b = line[i][1], c = line[i][2];
                long d = line[j][0], e = line[j][1], f = line[j][2];

                long denom = (a * e) - (b * d);
                if (denom == 0) continue;

                double x = (double) ((b * f) - (c * e)) / denom;
                double y = (double) ((c * d) - (a * f)) / denom;
                if ((long)x == x && (long) y == y) {
                    list.add(new Long[]{(long)x, (long)y});
                    szl = Math.min(szl, (long)x);
                    szr = Math.max(szr, (long)x);
                    szu = Math.max(szu, (long)y);
                    szd = Math.min(szd, (long)y);
                }
            }
        }

        int N = (int)(szu - szd + 1), M = (int)(szr - szl + 1);
        String[] answer =  new String[N];
        Arrays.fill(answer, ".".repeat(Math.max(0, M)));

        for (Long[] l : list) {
            int y = (int)(szu - l[1]), x = (int)(l[0] - szl);
            answer[y] = answer[y].substring(0, x) + "*" + answer[y].substring(x + 1);
        }
        return answer;
    }
}
