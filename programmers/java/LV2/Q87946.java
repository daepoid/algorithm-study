public class Q87946 {
    int answer = -1;

    public static void main(String[] args) {
        Q87946 question = new Q87946();
        int k = 80;
        int[][] dungeons = {{80, 20}, {50, 40}, {30, 10}};
        int result = question.solution(k, dungeons);
        System.out.println("result = " + result);
    }

    public void bruteforce(int tired, int[][] dungeons, int visited, int cnt) {
        answer = Math.max(answer, cnt);
        for (int i = 0; i < dungeons.length; i++) {
            if (((1 << i) & visited) != 0) {
                continue;
            }
            if (tired < dungeons[i][0]) {
                continue;
            }
            bruteforce(tired - dungeons[i][1], dungeons, visited | (1 << i), cnt + 1);
        }
    }

    public int solution(int k, int[][] dungeons) {
        for (int i = 0; i < dungeons.length; i++) {
            if (dungeons[i][0] <= k) {
                bruteforce(k - dungeons[i][1], dungeons, (1 << i), 1);
            }
        }
        return answer;
    }
}
