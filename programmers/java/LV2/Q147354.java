import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

public class Q147354 {
    public static void main(String[] args) {
        Q147354 q = new Q147354();
        int[][] data = {{2, 2, 6}, {1, 5, 10}, {4, 2, 9}, {3, 8, 3}};
        int col = 2;
        int row_begin = 2;
        int row_end = 3;
        int answer = q.solution(data, col, row_begin, row_end);
        System.out.println("answer = " + answer);
    }

    int compare(Data a, Data b, int idx) {
        if (Objects.equals(a.list.get(idx - 1), b.list.get(idx - 1))) {
            return b.list.getFirst() - a.list.getFirst();
        }
        return a.list.get(idx - 1) - b.list.get(idx - 1);
    }

    public int solution(int[][] data, int col, int row_begin, int row_end) {
        int answer = 0;
        List<Data> db = new ArrayList<>();
        for (int[] d : data) {
            Data temp = new Data();
            temp.list.addAll(Arrays.stream(d).boxed().toList());
            db.add(temp);
        }

        db.sort((a, b) -> compare(a, b, col));
        for (int i = row_begin - 1; i < row_end; i++) {
            int temp = 0;
            for (int j : db.get(i).list) {
                temp += (j % (i + 1));
            }
            answer ^= temp;
        }

        return answer;
    }

    private class Data {
        List<Integer> list;

        public Data() {
            this.list = new ArrayList<>();
        }
    }
}
