//
// Created by 박세현 on 2023/04/20.
//


#include "bits/stdc++.h"

#define MAX 11
using namespace std;

int N;
int cnt;
bool board[MAX][MAX];
int people[MAX];
deque<int> dq;

void dfs(int now) {
    if() {

    }

    for(int i = 1; i < N + 1; i++) {
        if(board[now][i]) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &people[i]);
    }
    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &cnt);
        int k;
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &k);
            board[i][k] = true;
        }
    }

    for (int i = 1; i < N + 1; i++) {
        dfs(i);
    }
}