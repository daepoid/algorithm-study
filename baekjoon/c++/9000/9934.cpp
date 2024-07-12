//
// Created by 박세현 on 2023/04/14.
//


#include "bits/stdc++.h"

#define MAX 11
using namespace std;


int K, arr[1025];
vector<int> board[MAX];

void dfs(int low, int high, int level) {
    if (low > high) {
        return;
    }

    if (low == high) {
        board[level].push_back(arr[low]);
        return;
    }

    int mid = (low + high) / 2;
    board[level].push_back(arr[mid]);
    dfs(low, mid - 1, level + 1);
    dfs(mid + 1, high, level + 1);
    return;
}

int main() {
    scanf("%d", &K);
    int N = pow(2, K) - 1;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    dfs(0, N, 1);

    for (int i = 1; i < K + 1; i++) {
        for (int j = 0; j < board[i].size(); j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}