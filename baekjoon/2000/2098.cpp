//
// Created by 박세현 on 2023/04/08.
//


#include "bits/stdc++.h"

#define MAX 16
#define INF 0x3f3f3f3f
using namespace std;

int N, board[MAX][MAX];
int dp[MAX][1 << MAX];

int tsp(int now, int visited) {
    if (visited == (1 << N) - 1) {
        return board[now][0] ? board[now][0] : INF;
    }

    if (dp[now][visited] != -1) {
        return dp[now][visited];
    }
    dp[now][visited] = INF;
    for (int i = 0; i < N; i++) {
        if (visited & (1 << i)) {
            continue;
        }
        if (board[now][i] == 0) {
            continue;
        }
        board[now][visited] = min(board[now][visited], tsp(i, visited | (1 << i)) + board[now][i]);
    }
    return board[now][visited];
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    int answer = tsp(0, 1);
    printf("%d\n", answer);
}