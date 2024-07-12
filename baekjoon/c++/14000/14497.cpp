//
// Created by 박세현 on 2023/04/12.
//


#include "bits/stdc++.h"

#define MAX 301
using namespace std;

int N, M;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
pair<int, int> junan, target;
string board[MAX];
bool visited[MAX][MAX];
bool flag = false;

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

void bfs() {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({junan.first, junan.second});

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
                visited[newy][newx] = true;
                q.push({newy, newx});
            } else if (board[newy][newx] == '1') {
                visited[newy][newx] = true;
            } else if (board[newy][newx] == '#') {
                visited[newy][newx] = true;
                flag = true;
                return;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) {
                board[i][j] = '0';
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    junan = {a - 1, b - 1};
    target = {c - 1, d - 1};

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    board[junan.first][junan.second] = '0';
    int cnt = 0;
    while (!flag) {
        cnt++;
        bfs();
    }
    printf("%d\n", cnt);
}