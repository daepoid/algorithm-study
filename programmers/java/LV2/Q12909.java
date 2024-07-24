import java.util.Stack;

public class Q12909 {
    public static void main(String[] args) {
        Q12909 question = new Q12909();
        String s = "()()";
        boolean result = question.solution(s);
        System.out.println("result = " + result);
    }

    boolean solution(String s) {
        Stack<Integer> stk = new Stack<>();
        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                stk.push(1);
            } else {
                if (stk.empty()) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
}
