//
// Created by 박세현 on 2023/04/06.
//

#include "bits/stdc++.h"

#define MAX 51
using namespace std;

int N, M;
int answer = 0;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

bool visited[MAX][MAX];
string board[MAX];

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

void bfs(int st_y, int st_x) {
    queue<pair<pair<int, int>, int> > q;
    memset(visited, false, sizeof(visited));
    q.push(make_pair(make_pair(st_y, st_x), 0));
    visited[st_y][st_x] = true;

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
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

            if (board[newy][newx] != 'L') {
                continue;
            }

            visited[newy][newx] = true;
            q.push(make_pair(make_pair(newy, newx), cnt + 1));
            answer = max(answer, cnt + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'L') {
                bfs(i, j);
            }
        }
    }

    cout << answer << "\n";
}
