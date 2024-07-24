public class Q70129 {
    public static void main(String[] args) {
        Q70129 question = new Q70129();
        String s = "110010101001";
        int[] result = question.solution(s);
        for (int i : result) {
            System.out.println("i = " + i);
        }
    }

    public int[] solution(String s) {
        int[] answer = {0, 0};
        while (!s.equals("1")) {
            String next = s.replace("0", "");
            answer[0] += 1;
            answer[1] += s.length() - next.length();
            s = Integer.toBinaryString(next.length());
        }
        return answer;
    }
}
