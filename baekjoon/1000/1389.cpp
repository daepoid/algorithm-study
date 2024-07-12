//
// Created by SeHyun on 2023-01-10.
//


#include "bits/stdc++.h"

#define MAX 101
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int A, B;
int board[MAX][MAX];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        board[A][B] = 1;
        board[B][A] = 1;
    }

    for (int k = 1; k < N + 1; k++) {
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                if (i == j) {
                    continue;
                }
                if (board[i][k] != 0 && board[k][j] != 0) {
                    if (board[i][j] == 0) {
                        board[i][j] = board[i][k] + board[k][j];
                    } else {
                        board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
                    }
                }
            }
        }
    }

    int sum = INF;
    int answer = 1;
    for (int i = 1; i < N + 1; i++) {
        int temp = 0;
        for (int j = 1; j < N + 1; j++) {
            temp += board[i][j];
        }
        if (temp < sum) {
            sum = temp;
            answer = i;
        }
    }
    printf("%d\n", answer);
}