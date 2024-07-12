//
// Created by SeHyun on 2023-02-03.
//


#include "bits/stdc++.h"

#define MAX_CNT 101
#define MAX_TIME 10001
using namespace std;

int N, T;

int K[MAX_CNT], S[MAX_CNT];
int dp[MAX_CNT][MAX_TIME];

int main() {

    scanf("%d %d", &N, &T);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &K[i], &S[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < T + 1; j++) {
            if (j - K[i] >= 0) {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - K[i]] + S[i]);
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }
    printf("%d\n", dp[N][T]);
}