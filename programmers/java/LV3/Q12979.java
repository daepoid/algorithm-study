public class Q12979 {
    public static void main(String[] args) {
        Q12979 question = new Q12979();
//        int n = 11, w = 1;
//        int[] stations = {4, 11};
//        int n = 16, w = 2;
//        int[] stations = {9};

        int n = 199999998, w = 1;
        int[] stations = {};

        int result = question.solution(n, stations, w);
        System.out.println("result = " + result);
    }

    public int sol(int start, int end, int w) {
        int len = end - start + 1;
        int maxRange = w * 2 + 1;
        if (len <= 0) return 0;
        return len / maxRange + (len % maxRange != 0 ? 1 : 0);
    }

    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        if (stations.length == 0) return sol(1, n, w);
        for (int i = 0; i < stations.length; i++) {
            if (i == 0) answer += sol(1, stations[i] - w - 1, w);
            else answer += sol(stations[i - 1] + w + 1, stations[i] - w - 1, w);
        }
        return answer + sol(stations[stations.length - 1] + w + 1, n, w);
    }
}
