public class Q17687 {
    public static void main(String[] args) {
        Q17687 question = new Q17687();
        int n = 2, t = 4, m = 2, p = 1;
        String result = question.solution(n, t, m, p);
        System.out.println("result = " + result);
    }

    public String solution(int n, int t, int m, int p) {
        String answer = "";
        int idx = 0;
        int turn = -1;
        boolean flag = true;
        while (flag) {
            String num = Integer.toString(idx, n);
            for (int i = 0; i < num.length(); i++) {
                turn = (turn + 1) % m;
                if (turn == p - 1) {
                    answer += Character.toUpperCase(num.charAt(i));
                }

                if (t == answer.length()) {
                    flag = false;
                    break;
                }
            }
            idx++;
        }
        return answer;
    }
}
