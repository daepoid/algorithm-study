//
// Created by 박세현 on 2023/04/05.
//


#include "bits/stdc++.h"

#define MAX 51
using namespace std;

int N, target, answer = 0;
bool board[MAX][MAX];

void dfs(int num) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (board[num][i] && i != target) {
            cnt++;
            dfs(i);
        }
    }

    if (cnt == 0) {
        answer++;
    }
}

int main() {
    scanf("%d", &N);
    int temp, root;
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        if (temp == -1) {
            root = i;
            continue;
        }
        board[temp][i] = true;
    }

    scanf("%d", &target);
    if (root != target) {
        dfs(root);
    }
    printf("%d\n", answer);
}