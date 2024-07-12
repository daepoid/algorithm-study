//
// Created by SeHyun on 2023-01-21.
//

#include "bits/stdc++.h"

#define MAX 31
using namespace std;

int N;
int dp[MAX];

int main() {

    scanf("%d", &N);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i < N + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
    }

    if (N % 2 == 1) {
        printf("%d\n", (dp[N] + dp[N / 2]) / 2);
    } else {
        printf("%d\n", (dp[N] + dp[N / 2] + dp[N / 2 - 1] * 2) / 2);
    }
}