#include<bits/stdc++.h>
using namespace std;

static deque<string> split(string str) {
	deque<string> tokens;
	string temp = "";
	for (char ch : str) {
		if (isdigit(ch)) {
			temp += ch;
		}
		else {
			tokens.push_back(temp);
			string op(1, ch);
			tokens.push_back(op);
			temp = "";
		}
	}
	tokens.push_back(temp);
	return tokens;
}

static string calculate(string eq) {
	deque<string> tokens = split(eq);
	deque<string> temp;
	string val1 = tokens.front();
	tokens.pop_front();

	while (!tokens.empty()) {
		string op = tokens.front();
		tokens.pop_front();
		if (op == "*") {
			string val2 = tokens.front();
			tokens.pop_front();
			val1 = to_string(stoi(val1) * stoi(val2));
		}
		else {
			temp.push_back(val1);
			temp.push_back(op);
			val1 = tokens.front();
			tokens.pop_front();
		}
	}
	tokens = temp;
	tokens.push_back(val1);

	val1 = tokens.front();
	tokens.pop_front();
	while (!tokens.empty()) {
		string op = tokens.front();
		tokens.pop_front();
		if (op == "+") {
			string val2 = tokens.front();
			tokens.pop_front();
			val1 = to_string(stoi(val1) + stoi(val2));
		}
	}
	return val1;
}

int main(int argc, char** argv) {
	int test_case, T = 10;
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		deque<string> stk;
		int num;
		string str;
		cin >> num >> str;

		for (int i = 0; i < num; i++) {
			if (str[i] == ')') {
				string temp = "";
				while (stk.back() != "(") {
					temp = stk.back() + temp;
					stk.pop_back();
				}
				stk.pop_back();
				stk.push_back(calculate(temp));
			}
			else {
				string temp(1, str[i]);
				stk.push_back(temp);
			}
		}

		cout << "#" << test_case << " " << stk.back() << "\n";
	}
	return 0;
}