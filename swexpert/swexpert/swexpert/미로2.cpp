#include<bits/stdc++.h>
using namespace std;

string board[101];
pair<int, int> s;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool is_valid(int newy, int newx) {
	return 0 <= newy && newy < 100 && 0 <= newx && newx < 100;
}

bool bfs() {
	bool visited[100][100];
	fill(&visited[0][0], &visited[0][0] + sizeof(visited), false);
	queue<pair<int, int>> q;
	q.push(s);
	visited[s.first][s.second] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newy = y + dy[i];
			int newx = x + dx[i];

			if (!is_valid(newy, newx)) {
				continue;
			}

			if (visited[newy][newx]) {
				continue;
			}

			if (board[newy][newx] == '0') {
				q.push({ newy, newx });
				visited[newy][newx] = true;
			}
			else if (board[newy][newx] == '3') {
				return true;
			}
		}
	}

	return false;
}

int main(int argc, char** argv) {
	int test_case;
	int T = 10;
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int tc;
		cin >> tc;
		getline(cin, board[0]);
		for (int i = 0; i < 100; i++) {
			getline(cin, board[i]);
			for (int j = 0; j < 100; j++) {
				if (board[i][j] == '2') {
					s = {i, j};
				}
			}
		}
		printf("#%d %d\n", tc, bfs());
	}
	return 0;
}