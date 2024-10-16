#include<bits/stdc++.h>
using namespace std;

int board[101][2];

bool bfs() {
	bool visited[101];
	fill(visited, visited + sizeof(visited), false);
	queue<int> q;
	q.push(0);
	visited[0] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int next = board[now][i];
			if (next == 99) {
				return true;
			} else if(next == -1) {
				continue;
			}

			if (visited[next]) {
				continue;
			}
			
			q.push(next);
			visited[next] = true;
		}
	}
	return false;
}

int main(int argc, char** argv) {
	int test_case;
	int T = 10;
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		fill(&board[0][0], &board[0][0] + sizeof(board), -1);
		int tc, lines;
		cin >> tc >> lines;
		for (int i = 0; i < lines; i++) {
			int a, b;
			cin >> a >> b;
			if (board[a][0] == -1) board[a][0] = b;
			else board[a][1] = b;
		}
		printf("#%d %d\n", tc, bfs());
	}
	return 0;
}