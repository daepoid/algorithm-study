#include<bits/stdc++.h>
using namespace std;

bool is_valid(int idx, int N, string tree[][3]) {
	if (idx * 2 + 1 <= N) {
		return !isdigit(tree[idx][0][0]) &&
			tree[idx][1] != "" && tree[idx][2] != "" &&
			is_valid(idx * 2, N, tree) && is_valid(idx * 2 + 1, N, tree);
	}
	else if (idx * 2 + 1 > N) {
		return isdigit(tree[idx][0][0]);
	}
	return false;
}

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

int main(int argc, char** argv) {
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case) {
		int N;
		cin >> N;
		string tree[201][3];
		string line;
		getline(cin, line);
		for (int i = 0; i < N; i++) {
			getline(cin, line);
			deque<string> tokens = split(line);
			int idx = stoi(tokens[0]);
			for (int j = 1; j < tokens.size() && j < 4; j++) {
				tree[idx][j - 1] = tokens[j];
			}
		}
		bool flag = is_valid(1, N, tree);
		printf("#%d %d\n", test_case, flag);
	}
	return 0;
}