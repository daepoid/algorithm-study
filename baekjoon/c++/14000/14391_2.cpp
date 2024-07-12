//
// Created by 박세현 on 2023/05/11.
//

#include "bits/stdc++.h"

#define MAX 5
using namespace std;

int N, M, answer;
int board[MAX][MAX];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    for (int k = 0; k < (1 << (N * M)); k++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int curr = 0;
            for (int j = 0; j < M; j++) {
                int idx = i * M + j;
                if ((k & (1 << idx)) == 0) { // 가로
                    curr = curr * 10 + board[i][j];
                } else {
                    sum += curr;
                    curr = 0;
                }
            }
            sum += curr;
        }

        for (int j = 0; j < M; j++) {
            int curr = 0;
            for (int i = 0; i < N; i++) {
                int idx = i * M + j;
                if ((k & (1 << idx)) == 0) {
                    sum += curr;
                    curr = 0;
                } else {
                    curr = curr * 10 + board[i][j];
                }
            }
            sum += curr;
        }
        answer = max(answer, sum);
    }
    printf("%d\n", answer);
}