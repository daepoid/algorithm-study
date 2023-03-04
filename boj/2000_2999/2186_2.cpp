//
// Created by SeHyun on 2023-02-23.
//

#include "bits/stdc++.h"

#define MAX 111
using namespace std;

int N, M, K;
int answer = 0;
string board[MAX];
string word;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int dp[MAX][MAX][81];

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

int dfs(int y, int x, int cnt) {
    if (dp[y][x][cnt] != -1) {
        return dp[y][x][cnt];
    }

    if (cnt == word.length()) {
        return 1;
    }

    dp[y][x][cnt] = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < K + 1; j++) {
            int newy = y + dy[i] * j;
            int newx = x + dx[i] * j;

            if (!is_valid(newy, newx)) {
                continue;
            }

            if (board[newy][newx] != word[cnt]) {
                continue;
            }
            dp[y][x][cnt] = dp[y][x][cnt] + dfs(newy, newx, cnt + 1);
        }
    }
    return dp[y][x][cnt];
}


int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    cin >> word;

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == word[0]) {
                answer += dfs(i, j, 1);
            }
        }
    }
    printf("%d\n", answer);
}