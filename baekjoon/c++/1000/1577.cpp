//
// Created by SeHyun on 2023-01-16.
//


#include "bits/stdc++.h"

#define MAX 101
#define ll long long
using namespace std;

int N, M, K;
ll dp[MAX][MAX];
int board[MAX][MAX][2];
int dy[2] = {1, 0};
int dx[2] = {0, 1};

ll solution(int y, int x) {
    if (y == N && x == M) {
        return 1;
    }
    if (dp[y][x] != 0) {
        return dp[y][x];
    }
    for (int i = 0; i < 2; i++) {
        if (board[y][x][i] == 0) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            if (newY < N + 1 && newX < M + 1) {
                dp[y][x] += solution(newY, newX);
            }
        }
    }
    return dp[y][x];
}

int main() {
    scanf("%d %d", &N, &M);
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a != b) {
            a = min(a, c);
            c = max(a, c);
            board[a][b][0] = 1;
        } else {
            b = min(b, d);
            d = max(b, d);
            board[a][b][1] = 1;
        }
    }
    printf("%lld\n", solution(0, 0));
}