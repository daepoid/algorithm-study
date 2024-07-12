//
// Created by SeHyun on 2023-03-01.
//


#include "bits/stdc++.h"

#define MAX 50001
using namespace std;

int N, M;
int sums[MAX], dp[4][MAX];


int main() {
    scanf("%d", &N);
    int temp;
    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &temp);
        sums[i] = sums[i - 1] + temp;
    }
    scanf("%d", &M);

    for (int i = 1; i <= 3; i++) {
        for (int j = i * M; j < N + 1; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - M] + (sums[j] - sums[j - M]));
        }
    }
    printf("%d\n", dp[3][N]);
}