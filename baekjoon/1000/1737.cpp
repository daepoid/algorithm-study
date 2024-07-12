//
// Created by SeHyun on 2023-01-28.
//


#include "bits/stdc++.h"

#define INV_INF -987654321
using namespace std;

int N, M;
vector<vector<int>> dp;
vector<int> arr;

int solution(int n, int m) {
    if (n == N) {
        if (m == 0) {
            return 0;
        }
        return INV_INF;
    }
    if (dp[n][m] != INV_INF) {
        return dp[n][m];
    }

    if (m > 0) {
        if (n + m < N + 1) {
            dp[n][m] = max(dp[n][m], solution(n + m, 0));
        }
    } else {
        dp[n][m] = max(dp[n][m], solution(n + 1, 0));
    }

    if (m + 1 < M + 1) {
        dp[n][m] = max(dp[n][m], solution(n + 1, m + 1) + arr[n]);
    }
    return dp[n][m];
}

int main() {
    scanf("%d %d", &N, &M);
    dp.resize(N + 1, vector<int>(M + 1, INV_INF));
    arr.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", solution(0, 0));
}