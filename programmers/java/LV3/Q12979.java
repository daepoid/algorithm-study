public class Q12979 {
    public static void main(String[] args) {
        Q12979 question = new Q12979();
//        int n = 11, w = 1;
//        int[] stations = {4, 11};
        int n = 16, w = 2;
        int[] stations = {9};

        int result = question.solution(n, stations, w);
        System.out.println("result = " + result);
    }

    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        int now = 1, next = 0, idx = 0;
        while (now <= w + 1) {
            if (now >= stations[idx] - w) {
                now = stations[idx];
                next = stations[idx] + w;
                idx++;
            }
            now++;
        }

        now = w + 1;
        if (next == 0) {
            answer++;
            next = now + w + 1;
        }

        while (now <= n) {
            if (next < stations[idx] - w) {
                answer++;
                now = next + w;
                next = now + w + 1;
            } else if (stations[idx] - w <= next) {
                now = stations[idx];
                next = stations[idx] + w + 1;
                idx++;
            }

            if (n < next) {
                break;
            } else if (idx == stations.length) {
                answer += (n - next) / (w * 2 + 1) + 1;
                break;
            }
        }

        return answer;
    }
}
