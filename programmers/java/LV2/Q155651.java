public class Q155651 {
    public static void main(String[] args) {
        Q155651 q = new Q155651();
        String[][] bookTime = {{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}};
        int answer = q.solution(bookTime);
        System.out.println("answer = " + answer);
    }

    public int solution(String[][] bookTime) {
        int answer = 0;
        int cleanTime = 10;
        int[] board = new int[60 * 60 * 24 + 1];
        for (String[] time : bookTime) {
            String[] beginTime = time[0].split(":");
            int begin = Integer.parseInt(beginTime[0]) * 60 + Integer.parseInt(beginTime[1]);
            String[] endTime = time[1].split(":");
            int end = Integer.parseInt(endTime[0]) * 60 + Integer.parseInt(endTime[1]) + cleanTime - 1;
            for (int i = begin; i <= end; i++) {
                board[i]++;
                answer = Math.max(answer, board[i]);
            }
        }
        return answer;
    }
}
