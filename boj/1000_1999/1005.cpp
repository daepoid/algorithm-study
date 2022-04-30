#include <bits/stdc++.h>
#define MAX 1011
using namespace std;

int T, N, K, W;
int times[MAX][2];
int cnts[MAX];
bool board[MAX][MAX];

void solution() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (cnts[i] == 0) {
            q.push(i);
            times[i][1] = times[i][0];
        }
    }
    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (num == W) {
            printf("%d\n", times[W][1]);
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (board[num][i]) {
                cnts[i]--;
                if (cnts[i] == 0) {
                    q.push(i);
                }
                times[i][1] = max(times[i][1], times[i][0] + times[num][1]);
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    while (T-- > 0) {
        memset(times, 0, sizeof(times));
        memset(board, false, sizeof(board));
        memset(cnts, 0, sizeof(cnts));
        scanf("%d %d", &N, &K);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &times[i][0]);
        }

        for (int i = 0; i < K; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            board[a][b] = true;
            cnts[b]++;
        }

        scanf("%d", &W);
        solution();
    }
}