#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T = 10;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int N;
		cin >> N;
		deque<int> dq;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			dq.push_back(temp);
		}
		sort(dq.begin(), dq.end());
		printf("#%d %d\n", test_case, dq[0] * dq[N - 1]);
	}
	return 0;
}