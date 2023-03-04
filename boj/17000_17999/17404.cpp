//
// Created by SeHyun on 2023-02-07.
//


#include "bits/stdc++.h"

#define MAX 1001
#define INF 0x3F3F3F3F
using namespace std;

int N;
int cost[MAX][3], dp[MAX][3];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }

    int answer = INF;
    for (int color = 0; color < 3; color++) {
        memset(dp, INF, sizeof(dp));
        dp[1][color] = cost[0][color];
        for (int i = 1; i < N; i++) {
            dp[i + 1][0] = min(dp[i][1], dp[i][2]) + cost[i][0];
            dp[i + 1][1] = min(dp[i][0], dp[i][2]) + cost[i][1];
            dp[i + 1][2] = min(dp[i][0], dp[i][1]) + cost[i][2];
        }
        for (int i = 0; i < 3; i++) {
            if (i != color) {
                answer = min(answer, dp[N][i]);
            }
        }
    }
    printf("%d\n", answer);
}