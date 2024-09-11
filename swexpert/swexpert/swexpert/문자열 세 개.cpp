#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int arr[3];
		string answer[3] = {"", "", ""};
		cin >> arr[0] >> arr[1] >> arr[2];
		if (arr[0] != arr[1]) {
			for (int i = 0; i < arr[0]; i++) {
				answer[0] += '0';
				answer[1] += '0';
			}
		}

		if (arr[1] != arr[2]) {
			for (int i = 0; i < arr[1]; i++) {
				answer[1] += '1';
				answer[2] += '1';
			}
		}

		if (arr[2] != arr[0]) {
			for (int i = 0; i < arr[2]; i++) {
				answer[0] += '0';
				answer[2] += '0';
			}
		}

		if (arr[0] == arr[1] && arr[1] == arr[2]) {
			for (int i = 0; i < arr[2]; i++) {
				answer[0] += '1';
				answer[1] += '1';
				answer[2] += '1';
			}
		}

		cout << "#" << test_case << " " << answer[0] << " " << answer[1] << " " << answer[2] << "\n";
	}
	return 0;
}