#include<bits/stdc++.h>
using namespace std;

double calculate_recurrsive(int idx, string tree[][3]) {
	if (isdigit(tree[idx][0][0])) {
		return stod(tree[idx][0]);
	}

	double val1 = calculate_recurrsive(stoi(tree[idx][1]), tree);
	double val2 = calculate_recurrsive(stoi(tree[idx][2]), tree);

	if (tree[idx][0] == "+") {
		return val1 + val2;
	}
	else if (tree[idx][0] == "-") {
		return val1 - val2;
	}
	else if (tree[idx][0] == "*") {
		return val1 * val2;
	}
	else if (tree[idx][0] == "/") {
		return val1 / val2;
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case) {
		int sz;
		cin >> sz;
		string tree[1001][3];
		for (int i = 0; i < sz; i++) {
			int idx;
			string s;
			cin >> idx >> s;
			if (isdigit(s[0])) {
				tree[idx][0] = s;
			}
			else {
				string l, r;
				cin >> l >> r;
				tree[idx][0] = s;
				tree[idx][1] = l;
				tree[idx][2] = r;
			}
		}

		double val = calculate_recurrsive(1, tree);
		printf("#%d %d\n", test_case, (int)val);
	}
	return 0;
}