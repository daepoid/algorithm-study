//
// Created by 박세현 on 2023/04/16.
//


#include "bits/stdc++.h"


#define MAX 6
using namespace std;

int R, C, K, answer = 0;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
string board[MAX];
bool visited[MAX][MAX];

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < R && 0 <= newx && newx < C;
}

void dfs(int y, int x, int cnt) {
    if (y == 0 && x == C - 1) {
        answer += cnt == K ? 1 : 0;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int newy = y + dy[i];
        int newx = x + dx[i];

        if (!is_valid(newy, newx)) {
            continue;
        }

        if (visited[newy][newx]) {
            continue;
        }

        if (board[newy][newx] == 'T') {
            continue;
        }

        visited[newy][newx] = true;
        dfs(newy, newx, cnt + 1);
        visited[newy][newx] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }
    visited[R - 1][0] = true;
    dfs(R - 1, 0, 1);
    cout << answer << "\n";
}