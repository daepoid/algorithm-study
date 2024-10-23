public class Q152995 {
    public static void main(String[] args) {
        Q152995 question = new Q152995();
        int[][] scores = {{2, 2}, {1, 4}, {3, 2}, {3, 2}, {2, 1}};
        int result = question.solution(scores);
        System.out.println("result = " + result);
    }
    public int solution(int[][] scores) {
        int answer = 1;
        for (int i = 1; i < scores.length; i++) {
            if (scores[0][0] + scores[0][1] < scores[i][0] + scores[i][1]) {
                if (scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1]) return -1;
                boolean flag = true;
                for (int j = 1; j < scores.length; j++) {
                    if (scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1]) {
                        flag = false;
                        break;
                    }
                }
                answer += (flag ? 1 : 0);
            }
        }
        return answer;
    }
}
