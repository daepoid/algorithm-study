//
// Created by SeHyun on 2023-02-04.
//


#include "bits/stdc++.h"

#define MAX 101
using namespace std;

int N, M;
int memories[MAX];
int cost[MAX];
int dp[MAX][MAX * MAX];

int main() {

    scanf("%d %d", &N, &M);
    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &memories[i]);
    }

    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &cost[i]);
    }

    int answer = 100 * 100 + 1;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < 100 * 100 + 1; j++) {
            if (j - cost[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memories[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
//                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }

            if (dp[i][j] >= M) {
                answer = min(answer, j);
            }
        }
    }
    printf("%d\n", answer);
}