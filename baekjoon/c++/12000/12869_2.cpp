//
// Created by SeHyun on 2023-02-05.
//


#include "bits/stdc++.h"

#define INF 1000000
#define MAX 61
using namespace std;

int N;
int dp[MAX][MAX][MAX];
int times[3];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &times[i]);
    }

    if (times[0] == 0 && times[1] == 0 && times[2] == 0) {
        printf("0\n");
        return 0;
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 0; i < times[0] + 1; i++) {
        for (int j = 0; j < times[1] + 1; j++) {
            for (int k = 0; k < times[2] + 1; k++) {
                if (dp[i][j][k] == INF) {
                    dp[min(i + 1, times[0])][min(j + 3, times[1])][min(k + 9, times[2])] = 1;
                    dp[min(i + 1, times[0])][min(j + 9, times[1])][min(k + 3, times[2])] = 1;
                    dp[min(i + 3, times[0])][min(j + 1, times[1])][min(k + 9, times[2])] = 1;
                    dp[min(i + 3, times[0])][min(j + 9, times[1])][min(k + 1, times[2])] = 1;
                    dp[min(i + 9, times[0])][min(j + 1, times[1])][min(k + 3, times[2])] = 1;
                    dp[min(i + 9, times[0])][min(j + 3, times[1])][min(k + 1, times[2])] = 1;
                } else {
                    dp[min(i + 1, times[0])][min(j + 3, times[1])][min(k + 9, times[2])] = min(
                            dp[min(i + 1, times[0])][min(j + 3, times[1])][min(k + 9, times[2])], dp[i][j][k] + 1);
                    dp[min(i + 1, times[0])][min(j + 9, times[1])][min(k + 3, times[2])] = min(
                            dp[min(i + 1, times[0])][min(j + 9, times[1])][min(k + 3, times[2])], dp[i][j][k] + 1);
                    dp[min(i + 3, times[0])][min(j + 1, times[1])][min(k + 9, times[2])] = min(
                            dp[min(i + 3, times[0])][min(j + 1, times[1])][min(k + 9, times[2])], dp[i][j][k] + 1);
                    dp[min(i + 3, times[0])][min(j + 9, times[1])][min(k + 1, times[2])] = min(
                            dp[min(i + 3, times[0])][min(j + 9, times[1])][min(k + 1, times[2])], dp[i][j][k] + 1);
                    dp[min(i + 9, times[0])][min(j + 1, times[1])][min(k + 3, times[2])] = min(
                            dp[min(i + 9, times[0])][min(j + 1, times[1])][min(k + 3, times[2])], dp[i][j][k] + 1);
                    dp[min(i + 9, times[0])][min(j + 3, times[1])][min(k + 1, times[2])] = min(
                            dp[min(i + 9, times[0])][min(j + 3, times[1])][min(k + 1, times[2])], dp[i][j][k] + 1);
                }
            }
        }
    }

    printf("%d\n", dp[times[0]][times[1]][times[2]]);
}