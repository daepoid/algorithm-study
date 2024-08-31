public class Q68646 {
    public static void main(String[] args) {
        Q68646 question = new Q68646();
        int[] a = {9, -1, -5};
//        int[] a = {-16, 27, 65, -2, 58, -92, -71, -68, -61, -33};
        int result = question.solution(a);
        System.out.println("result = " + result);
    }

    public int solution(int[] a) {
        int answer = 1;
        int l = 0, r = a.length - 1;
        int leftMin = a[l], rightMin = a[r];
        while (l < r) {
            if (leftMin > rightMin) {
                l++;
                if (a[l] < leftMin) {
                    leftMin = Math.min(leftMin, a[l]);
                    answer++;
                }
            } else {
                r--;
                if (a[r] < rightMin) {
                    answer++;
                    rightMin = Math.min(rightMin, a[r]);
                }
            }
        }
        return answer;
    }
}
