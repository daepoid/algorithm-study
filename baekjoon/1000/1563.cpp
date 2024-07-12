//
// Created by SeHyun on 2023-01-21.
//

#include "bits/stdc++.h"

#define MAX_DAY 1001
#define MAX_LATE 2
#define MAX_ABSENCE 3
#define MOD 1000000
using namespace std;

int N;
int dp[MAX_DAY][MAX_LATE][MAX_ABSENCE];

int main() {
    scanf("%d", &N);
    dp[0][0][0] = 1;

    for (int i = 1; i < N + 1; i++) {
        dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
        dp[i][0][1] = (dp[i - 1][0][0]) % MOD;
        dp[i][0][2] = (dp[i - 1][0][1]) % MOD;
        dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] +
                       dp[i - 1][1][2]) % MOD;
        dp[i][1][1] = (dp[i - 1][1][0]) % MOD;
        dp[i][1][2] = (dp[i - 1][1][1]) % MOD;
    }
    int answer = 0;
    for (int i = 0; i < MAX_LATE; i++) {
        for (int j = 0; j < MAX_ABSENCE; j++) {
            answer += dp[N][i][j];
            answer %= MOD;
        }
    }
    printf("%d\n", answer);
}