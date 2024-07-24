import java.util.Stack;

public class Q76502 {
    public static void main(String[] args) {
        Q76502 question = new Q76502();
        String s = "[](){}";
        int result = question.solution(s);
        System.out.println("result = " + result);
    }

    public int solution(String s) {
        int answer = 0;
        for (int i = 0; i < s.length(); i++) {
            String str = s.substring(i, s.length()) + s.substring(0, i);
            Stack<Character> stk = new Stack<>();

            for (int j = 0; j < str.length(); j++) {
                char ch = str.charAt(j);
                if (stk.isEmpty()) {
                    stk.push(ch);
                } else if (stk.peek() == '(' && ch == ')') {
                    stk.pop();
                } else if (stk.peek() == '{' && ch == '}') {
                    stk.pop();
                } else if (stk.peek() == '[' && ch == ']') {
                    stk.pop();
                } else {
                    stk.push(ch);
                }
            }
            if (stk.isEmpty()) {
                answer++;
            }
        }
        return answer;
    }
}
