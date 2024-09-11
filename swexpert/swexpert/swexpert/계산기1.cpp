#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int test_case, T = 10, num;
	string eq;
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		deque<string> stk;
		cin >> num >> eq;

		int sum = 0;
		for (int i = 0; i < num; i += 2) {
			sum += eq[i] - '0';
		}
		cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;
}