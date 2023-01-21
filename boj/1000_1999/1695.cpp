//
// Created by SeHyun on 2023-01-21.
//


#include "bits/stdc++.h"

#define MAX 5001
using namespace std;

int N;
int arr[MAX];
int dp[MAX][MAX];

int palindrome(int i, int j) {
    if (i >= j) {
        return dp[i][j] = 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (arr[i] == arr[j]) {
        return dp[i][j] = palindrome(i + 1, j - 1);
    } else {
        return dp[i][j] = min(palindrome(i, j - 1), palindrome(i + 1, j)) + 1;
    }
}

int main() {
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N + 1; j++) {
            palindrome(i, j);
        }
    }
    printf("%d\n", dp[1][N]);
}