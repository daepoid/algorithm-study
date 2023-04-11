//
// Created by 박세현 on 2023/04/04.
//

#include "bits/stdc++.h"

#define MAX 8
#define WALLS 3
using namespace std;

int N, M, safety, answer = 0;
int board[MAX][MAX], temp[MAX][MAX];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
vector<pair<int, int> > v;

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

void bfs() {
    int cnt = safety - WALLS;
    int temp2[MAX][MAX];
    memcpy(temp2, temp, sizeof(temp));
    queue<pair<int, int> > q;

    for (int i = 0; i < v.size(); i++) {
        q.push(make_pair(v[i].first, v[i].second));
    }

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

            if (temp2[newy][newx] != 0) {
                continue;
            }

            q.push(make_pair(newy, newx));
            temp2[newy][newx] = 2;
            cnt--;
        }
    }
    answer = max(answer, cnt);
}

void build_walls(int cnt) {
    if (cnt == 3) {
        bfs();
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 0) {
                temp[i][j] = 1;
                build_walls(cnt + 1);
                temp[i][j] = 0;
            }
        }
    }

}

int main() {
    scanf("%d %d", &N, &M);
    safety = N * M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] != 0) {
                safety--;
            }

            if (board[i][j] == 2) {
                v.push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                memcpy(temp, board, sizeof(board));
                temp[i][j] = 1;
                build_walls(1);
            }
        }
    }

    printf("%d\n", answer);
}