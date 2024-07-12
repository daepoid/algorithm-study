//
// Created by SeHyun on 2023-02-02.
//

#include "bits/stdc++.h"

#define MAX_N 5001
#define MAX_M 10001
using namespace std;


int N, M;
float f;
int prices[MAX_N], calories[MAX_N];
int dp[MAX_M];

int main() {
    while (true) {
        scanf("%d %f", &N, &f);
        M = f * 100 + 0.5;
        if (N == 0 && M == 0) {
            return 0;
        }

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++) {
            scanf("%d %f", &calories[i], &f);
            prices[i] = f * 100;
        }

        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < M + 1; j++) {
                if (j - prices[i] >= 0) {
                    dp[j] = max(dp[j], dp[j - prices[i]] + calories[i]);
                    answer = max(answer, dp[j]);
                }
            }
        }
        printf("%d\n", answer);
    }
}