//
// Created by 박세현 on 2023/04/02.
//


#include "bits/stdc++.h"

#define MAX 101
using namespace std;

int N;
int board[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

void bfs(int a, int b, int threshold) {
    visited[a][b] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));

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

            if (board[newy][newx] <= threshold) {
                continue;
            }

            visited[newy][newx] = true;
            q.push(make_pair(newy, newx));
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max_height = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            max_height = max(max_height, board[i][j]);
        }
    }

    int answer = 0;
    for (int k = 0; k < max_height + 1; k++) {
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && board[i][j] - k > 0) {
                    bfs(i, j, k);
                    cnt++;
                }
            }
        }
        answer = max(answer, cnt);
    }
    cout << answer << "\n";
}