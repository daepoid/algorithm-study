//
// Created by SeHyun on 2023-01-14.
//

#include "bits/stdc++.h"

#define MAX_N 21
#define MAX_C 1001
using namespace std;

int C, N;
int cost[MAX_N], customer[MAX_N];
int dp[100 * MAX_C]; // idx : 금액, val : 고객의 수

int main() {
    scanf("%d %d", &C, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &cost[i], &customer[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < 100001; j++) {
            if (j - cost[i] >= 0) {
                dp[j] = max(dp[j], dp[j - cost[i]] + customer[i]);
            }
        }
    }
    for (int i = 1; i < 100001; i++) {
        if (dp[i] >= C) {
            printf("%d\n", i);
            return 0;
        }
    }
}