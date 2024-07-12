//
// Created by SeHyun on 2023-02-26.
//


#include "bits/stdc++.h"

#define MAX 1001
#define MOD 1000000003
using namespace std;

int N, K;
int dp[MAX][MAX];

int main() {
    scanf("%d", &N);
    scanf("%d", &K);

    dp[1][1] = 1;
    for (int i = 2; i < N + 1; i++) {
        for (int j = 1; j * 2 <= i; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
}