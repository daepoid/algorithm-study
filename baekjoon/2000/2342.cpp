//
// Created by SeHyun on 2023-02-24.
//

// https://barbera.tistory.com/m/37

#include "bits/stdc++.h"

#define MAX 100001
#define INF 0x3f3f3f3f
using namespace std;

int dp[MAX][5][5];
int answer = INF;

int dist(int a, int b) {
    if (a == b) {
        return 1;
    }

    if (a == 0) {
        return 2;
    }

    a--;
    b--;

    if ((a + 1) % 4 == b || (a + 3) % 4 == b) {
        return 3;
    } else if ((a + 2) % 4 == b) {
        return 4;
    }
    return INF;
}

int main() {
    int num;

    memset(dp, INF, sizeof(dp));
    dp[0][0][0] = 0;

    int idx = 0;
    while (true) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (dp[idx][i][j] >= INF) {
                    continue;
                }
                dp[idx + 1][i][num] = min(dp[idx + 1][i][num], dp[idx][i][j] + dist(j, num));
                dp[idx + 1][num][j] = min(dp[idx + 1][num][j], dp[idx][i][j] + dist(i, num));
            }
        }
        idx++;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            answer = min(answer, dp[idx][i][j]);
        }
    }

    printf("%d\n", answer);
}