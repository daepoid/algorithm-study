//
// Created by SeHyun on 2023-02-03.
//


#include "bits/stdc++.h"

#define MAX_N 101
#define MAX_K 100001
using namespace std;

int N, K;
int weight[MAX_N], values[MAX_N];
int dp[MAX_N][MAX_K];


int main() {

    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &weight[i], &values[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K + 1; j++) {
            if (j - weight[i] >= 0) {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - weight[i]] + values[i]);
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    printf("%d\n", dp[N][K]);
}