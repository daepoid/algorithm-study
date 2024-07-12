//
// Created by SeHyun on 2023-02-20.
//

#include "bits/stdc++.h"

#define MAX 1111
#define INF 0x3f3f3f3f
using namespace std;

int T, N, K, W;
int cnt[MAX], times[MAX], dp[MAX];
bool board[MAX][MAX];

void solution() {
    queue<int> q;
    for (int i = 1; i < N + 1; i++) {
        if (cnt[i] == 0) {
            q.push(i);
            dp[i] = times[i];
        }
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        if (idx == W) {
            printf("%d\n", dp[W]);
            return;
        }

        for (int i = 1; i < N + 1; i++) {
            if (!board[idx][i]) {
                continue;
            }

            cnt[i]--;
            if (cnt[i] == 0) {
                q.push(i);
            }

            dp[i] = max(dp[i], dp[idx] + times[i]);
        }
    }

}

int main() {
    scanf("%d", &T);
    while (T-- > 0) {
        memset(times, 0, sizeof(times));
        memset(dp, 0, sizeof(dp));
        memset(board, false, sizeof(board));
        memset(cnt, 0, sizeof(cnt));

        scanf("%d %d", &N, &K);

        for (int i = 1; i < N + 1; i++) {
            scanf("%d", &times[i]);
        }

        int a, b;
        for (int i = 0; i < K; i++) {
            scanf("%d %d", &a, &b);
            board[a][b] = true;
            cnt[b]++;
        }

        scanf("%d", &W);
        solution();
    }
}