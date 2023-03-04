//
// Created by SeHyun on 2023-03-03.
//


#include "bits/stdc++.h"

#define MAX 1011
using namespace std;

int N, M, answer;
int board[MAX][MAX];
vector<pair<int, int>> walls;
int H, W, SR, SC, FR, FC;

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

bool isValid(int newr, int newc) {
    return 0 < newr && newr + H <= N + 1 && 0 < newc && newc + W <= M + 1;
}

bool hasWall(int newr, int newc) {
    for (int i = 0; i < walls.size(); i++) {
        if (newr <= walls[i].first && walls[i].first < newr + H && newc <= walls[i].second &&
            walls[i].second < newc + W) {
            return true;
        }
    }
    return false;
}

int bfs() {
    bool visited[MAX][MAX];
    queue<pair<pair<int, int>, int>> q;
    q.push({{SR, SC}, 0});
    visited[SR][SC] = true;

    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (r == FR && c == FC) {
            return cnt;
        }

        for (int i = 0; i < 4; i++) {
            int newr = r + dr[i];
            int newc = c + dc[i];

            if (!isValid(newr, newc)) {
                continue;
            }

            if (hasWall(newr, newc)) {
                continue;
            }

            if (visited[newr][newc]) {
                continue;
            }

            q.push({{newr, newc}, cnt + 1});
            visited[newr][newc] = true;
        }
    }
    return -1;
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 1) {
                walls.push_back({i, j});
            }
        }
    }

    scanf("%d %d %d %d %d %d", &H, &W, &SR, &SC, &FR, &FC);

    answer = bfs();
    printf("%d\n", answer);
}