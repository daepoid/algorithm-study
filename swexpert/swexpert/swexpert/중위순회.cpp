#include<bits/stdc++.h>
using namespace std;

deque<string> split(string s) {
	deque<string> tokens;
	string temp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			tokens.push_back(temp);
			temp = "";
		}
		else {
			temp += s[i];
		}
	}
	if (temp != "") {
		tokens.push_back(temp);
	}
	return tokens;
}

string inorder(int idx, string tree[][3]) {
	string left = "", right = "";
	if (tree[idx][1] != "") {
		left = inorder(stoi(tree[idx][1]), tree);
	}
	if (tree[idx][2] != "") {
		right = inorder(stoi(tree[idx][2]), tree);
	}

	return left + tree[idx][0] + right;
}

int main(int argc, char** argv) {
	int test_case;
	int T = 10, N;
	string line;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> N;
		string tree[101][3];
		getline(cin, line);
		for (int i = 0; i < N; i++) {
			getline(cin, line);
			deque<string> tokens = split(line);
			int idx = stoi(tokens[0]);
			for (int j = 1; j < tokens.size() && j < 4; j++) {
				tree[idx][j - 1] = tokens[j];
			}
		}
		string answer = inorder(1, tree);
		printf("#%d %s\n", test_case, answer.c_str());
	}
	return 0;
}