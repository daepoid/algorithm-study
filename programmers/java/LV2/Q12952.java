public class Q12952 {
    int answer;
    int[] board;

    public static void main(String[] args) {
        Q12952 question = new Q12952();
        int n = 4;
        int result = question.solution(n);
        System.out.println("result = " + result);
    }

    boolean isValid(int idx) {
        for (int i = 0; i < idx; i++) {
            if (board[i] == board[idx]) return false;
            if (idx - i == Math.abs(board[idx] - board[i])) return false;
        }
        return true;
    }

    void countCombination(int idx) {
        if (idx == board.length) {
            answer++;
            return;
        }

        for (int i = 0; i < board.length; i++) {
            board[idx] = i;
            if (isValid(idx)) {
                countCombination(idx + 1);
            }
        }
    }

    public int solution(int n) {
        board = new int[n];
        countCombination(0);
        return answer;
    }
}
