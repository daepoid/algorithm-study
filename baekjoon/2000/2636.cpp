//
// Created by 박세현 on 2023/04/05.
//


#include "bits/stdc++.h"

#define MAX 101
using namespace std;

int N, M, cheese, turn = 0;
int board[MAX][MAX], temp[MAX][MAX];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
bool visited[MAX][MAX];
vector<int> v;

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

void bfs() {
    queue<pair<int, int> > q;
    memset(visited, false, sizeof(visited));
    q.push(make_pair(0, 0));
    visited[0][0] = true;

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

            if (board[newy][newx] == 0) {
                q.push(make_pair(newy, newx));
            } else {
                cheese--;
            }

            visited[newy][newx] = true;
        }
    }
    v.push_back(cheese);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 1) {
                cheese++;
            }
        }
    }
    v.push_back(cheese);

    while (true) {
        if (cheese == 0) {
            break;
        }
        bfs();
        memcpy(temp, board, sizeof(board));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = (temp[i][j] == 1 && !visited[i][j]) ? 1 : 0;
            }
        }
        turn++;
    }

    printf("%d\n", turn);
    printf("%d\n", v[v.size() - 2]);
}