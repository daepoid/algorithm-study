//
// Created by SeHyun on 2023-02-27.
//



#include "bits/stdc++.h"

#define MAX 101
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int dp[MAX][MAX / 2 + 1], sum[MAX][MAX], arr[MAX];

int solution(int n, int m) {
    if (m == M) {
        return 0;
    }
    if (n >= N) {
        return -INF;
    }

    if (dp[n][m] != INF) {
        return dp[n][m];
    }

    dp[n][m] = solution(n + 1, m);
    for (int i = n; i < N; i++) {
        dp[n][m] = max(dp[n][m], sum[n][i] + solution(i + 2, m + 1));
    }
    return dp[n][m];
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    memset(dp, INF, sizeof(dp));

    for (int i = 0; i < N; i++) {
        int temp = 0;
        for (int j = i; j < N; j++) {
            temp += arr[j];
            sum[i][j] = temp;
        }
    }
    printf("%d\n", solution(0, 0));
}