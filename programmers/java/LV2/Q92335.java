public class Q92335 {
    public static void main(String[] args) {
        Q92335 question = new Q92335();
        int n = 437674, k = 3;
        int result = question.solution(n, k);
        System.out.println("result = " + result);
    }

    boolean isPrime(String strNum) {
        long num = Long.parseLong(strNum);
        if (num < 2) {
            return false;
        }
        for (int i = 2; i < (long) Math.sqrt(num) + 1; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public int solution(int n, int k) {
        int answer = 0;
        String strNum = Integer.toString(n, k);
        String[] splits = strNum.split("0");
        for (String split : splits) {
            if (!split.isEmpty()) {
                answer += isPrime(split) ? 1 : 0;
            }
        }
        return answer;
    }
}
