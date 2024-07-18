import java.util.Arrays;

public class Q12987 {
    public static void main(String[] args) {
        Q12987 q = new Q12987();
        int[] A = {7, 3, 1, 5};
        int[] B = {8, 3, 1, 6};
        int result = q.solution(A, B);
        System.out.println("result = " + result);
    }

    public int solution(int[] A, int[] B) {
        int answer = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        for (int i = A.length - 1, j = B.length - 1; i >= 0 && j >= 0; i--, j--) {
            if (A[i] < B[j]) {
                answer++;
            } else if (A[i] >= B[j]) {
                j++;
            }
        }
        return answer;
    }
}
