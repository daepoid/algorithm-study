//
// Created by SeHyun on 2023-01-20.
//


#include "bits/stdc++.h"

#define MAX_TIME 1001
#define MAX_MOVE 31
using namespace std;


int T, W;
int dp[2][MAX_TIME][MAX_MOVE];
int answer = -1;

int main() {
    int temp;
    scanf("%d %d", &T, &W);
    for (int i = 1; i < T + 1; i++) {
        scanf("%d", &temp);
        for (int j = 0; j < W + 1; j++) {
            if (j == 0) {
                dp[0][j][i] = dp[0][j][i - 1] + (temp == 1 ? 1 : 0);
            } else {
                dp[0][j][i] = max(dp[1][j - 1][i - 1] + (temp == 1 ? 1 : 0), dp[0][j][i - 1] + (temp == 1 ? 1 : 0));
                dp[1][j][i] = max(dp[0][j - 1][i - 1] + (temp == 2 ? 1 : 0), dp[1][j][i - 1] + (temp == 2 ? 1 : 0));
            }
        }
    }


    for (int i = 0; i < W + 1; i++) {
        answer = max(answer, max(dp[0][i][T], dp[1][i][T]));
    }
    printf("%d\n", answer);
}