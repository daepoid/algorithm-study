//
// Created by 박세현 on 2023/04/17.
//


#include "bits/stdc++.h"

#define MAX 16
#define INF 1000000
using namespace std;

int N, MP, MF, MS, MV, answer = INF;
int board[MAX][5];

deque<int> dq, ans_arr;


void dfs(int idx) {
    int p = 0, f = 0, s = 0, v = 0, c = 0;
    for (int i = 0; i < dq.size(); i++) {
        p += board[dq[i]][0];
        f += board[dq[i]][1];
        s += board[dq[i]][2];
        v += board[dq[i]][3];
        c += board[dq[i]][4];

        if (MP <= p && MF <= f && MS <= s && MV <= v && c < answer) {
            answer = c;
            ans_arr = dq;
            return;
        }
    }

    for (int i = idx; i < N; i++) {
        dq.push_back(i);
        dfs(i + 1);
        dq.pop_back();
    }
}


int main() {
    scanf("%d", &N);
    scanf("%d %d %d %d", &MP, &MF, &MS, &MV);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d %d", &board[i][0], &board[i][1], &board[i][2], &board[i][3], &board[i][4]);
    }

    dfs(0);

    if (answer == INF) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", answer);
    for (int i = 0; i < ans_arr.size(); i++) {
        printf("%d ", ans_arr[i] + 1);
    }
    printf("\n");
}