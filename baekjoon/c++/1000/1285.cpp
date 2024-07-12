//
// Created by 박세현 on 2023/04/19.
//

#include "bits/stdc++.h"

#define MAX 21
#define INF 0x3f3f3f3f
using namespace std;

int N;
string board[MAX];
int answer = INF;

void dfs(int now) {
    if (now == N + 1) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int cnt = 0;
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'T') {
                    cnt++;
                }
            }
            sum += min(cnt, N - cnt);
        }
        answer = min(answer, sum);
        return;
    }
    dfs(now + 1);
    for (int i = 0; i < N; i++) {
        board[i][now] = board[i][now] == 'T' ? 'H' : 'T';
    }
    dfs(now + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    dfs(1);

    cout << answer << "\n";
}