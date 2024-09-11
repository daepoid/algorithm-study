package java;

import java.util.Scanner;
import java.util.*;

class Solution {
	
	static void solution() {
		
	}
	
	static int calculateStringEquation(String equation) {
		return 11;
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			Stack<String> stk = new Stack<>();
			char[] charArray = sc.nextLine().toCharArray();
			
			for (char ch : charArray) {
				if (ch == ')') {
					StringBuilder sb = new StringBuilder();
					while (stk.peek() != "(") {
						sb.insert(0, stk.peek());
						stk.pop();
					}
					stk.pop();
					int result = calculateStringEquation(sb.toString());
					stk.add(String.valueOf(result));
				} else {
					stk.add(String.valueOf(ch));
				}
			}
			System.out.println(stk.peek());
		}
	}
}