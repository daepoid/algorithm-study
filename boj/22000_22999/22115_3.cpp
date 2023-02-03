//
// Created by SeHyun on 2023-02-03.
//

#include "bits/stdc++.h"

#define MAX_N 101
#define MAX_CAFFEINE 100001
#define INF 0x7F
using namespace std;


int N, K;
int caffeine[MAX_N];
int dp[MAX_N][MAX_CAFFEINE];

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &caffeine[i]);
    }

    for (int i = 0; i < K + 1; i++) {
        dp[0][i] = INF;
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < K + 1; j++) {
            if (j - caffeine[i] >= 0) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - caffeine[i]] + 1);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d\n", dp[N][K] == INF ? -1 : dp[N][K]);
}