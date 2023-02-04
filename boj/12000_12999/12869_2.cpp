//
// Created by SeHyun on 2023-02-05.
//


#include "bits/stdc++.h"

#define INF 1000000
#define MAX 61
using namespace std;

int N;
int dp[MAX][MAX][MAX];
int arr[3];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
        printf("0\n");
        return 0;
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 0; i < arr[0] + 1; i++) {
        for (int j = 0; j < arr[1] + 1; j++) {
            for (int k = 0; k < arr[2] + 1; k++) {
                if (dp[i][j][k] == INF) {
                    dp[min(i + 1, arr[0])][min(j + 3, arr[1])][min(k + 9, arr[2])] = 1;
                    dp[min(i + 1, arr[0])][min(j + 9, arr[1])][min(k + 3, arr[2])] = 1;
                    dp[min(i + 3, arr[0])][min(j + 1, arr[1])][min(k + 9, arr[2])] = 1;
                    dp[min(i + 3, arr[0])][min(j + 9, arr[1])][min(k + 1, arr[2])] = 1;
                    dp[min(i + 9, arr[0])][min(j + 1, arr[1])][min(k + 3, arr[2])] = 1;
                    dp[min(i + 9, arr[0])][min(j + 3, arr[1])][min(k + 1, arr[2])] = 1;
                } else {
                    dp[min(i + 1, arr[0])][min(j + 3, arr[1])][min(k + 9, arr[2])] = min(
                            dp[min(i + 1, arr[0])][min(j + 3, arr[1])][min(k + 9, arr[2])], dp[i][j][k] + 1);
                    dp[min(i + 1, arr[0])][min(j + 9, arr[1])][min(k + 3, arr[2])] = min(
                            dp[min(i + 1, arr[0])][min(j + 9, arr[1])][min(k + 3, arr[2])], dp[i][j][k] + 1);
                    dp[min(i + 3, arr[0])][min(j + 1, arr[1])][min(k + 9, arr[2])] = min(
                            dp[min(i + 3, arr[0])][min(j + 1, arr[1])][min(k + 9, arr[2])], dp[i][j][k] + 1);
                    dp[min(i + 3, arr[0])][min(j + 9, arr[1])][min(k + 1, arr[2])] = min(
                            dp[min(i + 3, arr[0])][min(j + 9, arr[1])][min(k + 1, arr[2])], dp[i][j][k] + 1);
                    dp[min(i + 9, arr[0])][min(j + 1, arr[1])][min(k + 3, arr[2])] = min(
                            dp[min(i + 9, arr[0])][min(j + 1, arr[1])][min(k + 3, arr[2])], dp[i][j][k] + 1);
                    dp[min(i + 9, arr[0])][min(j + 3, arr[1])][min(k + 1, arr[2])] = min(
                            dp[min(i + 9, arr[0])][min(j + 3, arr[1])][min(k + 1, arr[2])], dp[i][j][k] + 1);
                }
            }
        }
    }

    printf("%d\n", dp[arr[0]][arr[1]][arr[2]]);
}