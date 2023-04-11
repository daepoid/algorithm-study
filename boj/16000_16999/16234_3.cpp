//
// Created by 박세현 on 2023/04/06.
//


#include "bits/stdc++.h"

#define MAX 51
using namespace std;

int N, L, R;
int answer = 0;
int board[MAX][MAX];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
bool visited[MAX][MAX];

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

bool is_movable(int val) {
    return L <= val && val <= R;
}

void bfs(int st_y, int st_x) {
    int sum = board[st_y][st_x], cnt = 1;
    queue<pair<int, int> > q, moveq;
    q.push(make_pair(st_y, st_x));
    moveq.push(make_pair(st_y, st_x));
    visited[st_y][st_x] = true;

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

            if (is_movable(abs(board[newy][newx] - board[y][x]))) {
                visited[newy][newx] = true;
                q.push(make_pair(newy, newx));
                moveq.push(make_pair(newy, newx));
                sum += board[newy][newx];
                cnt++;
            }
        }
    }

    int val = sum / cnt;
    while (!moveq.empty()) {
        int y = moveq.front().first;
        int x = moveq.front().second;
        moveq.pop();
        board[y][x] = val;
    }
}

int main() {
    scanf("%d %d %d", &N, &L, &R);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    bool flag = true;
    while (flag) {
        flag = false;
        memset(visited, false, sizeof(visited));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {

                for (int i = 0; i < 4; i++) {
                    int newy = y + dy[i];
                    int newx = x + dx[i];

                    if (visited[y][x]) {
                        continue;
                    }

                    if (!is_valid(newy, newx)) {
                        continue;
                    }

                    if (!is_movable(abs(board[newy][newx] - board[y][x]))) {
                        continue;
                    }

                    bfs(y, x);
                    flag = true;
                }

            }
        }

        if (flag) {
            answer++;
        }
    }

    printf("%d\n", answer);
}