public class Q12923 {
    public static void main(String[] args) {
        Q12923 question = new Q12923();
        long begin = 1;
        long end = 10;
        int[] result = question.solution(begin, end);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public int[] solution(long begin, long end) {

        int[] answer = new int[(int) (end - begin) + 1];
        for (long i = begin; i < end + 1; i++) {
            long maxVal = 1;
            for (long j = 2; j <= Math.sqrt(i); j++) {
                if (i % j == 0) maxVal = Math.max(maxVal, (i / j <= 10_000_000 ? Math.max(j, i / j) : j));
            }
            answer[(int) (i - begin)] = (int) maxVal;
        }
        if (begin == 1) answer[0] = 0;
        return answer;
    }
}
