//
// Created by SeHyun on 2023-02-05.
//

#include "bits/stdc++.h"

#define MAX 101
#define INF 0x7F7F7F7F
using namespace std;

int N, M;
bool rest[MAX];
int dp[MAX][MAX];
int price[] = {0, 10000, 0, 25000, 0, 37000};

int dfs(int cnt, int coupon) {
    if (cnt > N) {
        return 0;
    }

    if (dp[cnt][coupon] != INF) {
        return dp[cnt][coupon];
    }

    if (rest[cnt]) {
        dp[cnt][coupon] = dfs(cnt + 1, coupon);
        return dp[cnt][coupon];
    }

    dp[cnt][coupon] = min(dp[cnt][coupon], dfs(cnt + 1, coupon) + price[1]);
    dp[cnt][coupon] = min(dp[cnt][coupon], dfs(cnt + 3, coupon + 1) + price[3]);
    dp[cnt][coupon] = min(dp[cnt][coupon], dfs(cnt + 5, coupon + 2) + price[5]);

    if (coupon >= 3) {
        dp[cnt][coupon] = min(dp[cnt][coupon], dfs(cnt + 1, coupon - 3));
    }

    return dp[cnt][coupon];
}

int main() {
    int temp;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &temp);
        rest[temp] = true;
    }
    memset(dp, INF, sizeof(dp));

    printf("%d\n", dfs(1, 0));
}