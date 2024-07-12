//
// Created by SeHyun on 2023-02-25.
//


#include "bits/stdc++.h"

#define MOD 1000000003
#define MAX 1001
using namespace std;

int N, K;
int dp[MAX][MAX];

int main() {
    scanf("%d", &N);
    scanf("%d", &K);

    for (int i = 0; i < N + 1; i++) {
        dp[i][0] = 1;
    }

    dp[1][1] = 1;

    for (int i = 2; i < N + 1; i++) {
        for (int j = 1; j * 2 <= i + 1; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    printf("%d\n", (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD);
}