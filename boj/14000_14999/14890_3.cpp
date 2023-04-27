//
// Created by 박세현 on 2023/04/26.
//


#include "bits/stdc++.h"

#define MAX 101
using namespace std;

int N, L, answer = 0;
int board[MAX][MAX];

int main() {
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        int bf = board[i][0];
        bool flag = true;
        int flat = 1;
        for (int j = 1; j < N;) {
            if (bf == board[i][j]) {
                flat++;
            } else if (bf + 1 == board[i][j]) {
                if (flat < L) {
                    flag = false;
                    break;
                }
                bf = bf + 1;
                flat = 1;
            } else if (bf - 1 == board[i][j]) {
                if (N < j + L) {
                    flag = false;
                    break;
                }
                int cnt = 0;
                for (int k = j; k < j + L; k++) {
                    if (board[i][k] == bf - 1) {
                        cnt++;
                    }
                }
                if (cnt != L) {
                    flag = false;
                    break;
                }
                flat = 0;
                bf = bf - 1;
                j = j + L - 1;
            } else {
                flag = false;
                break;
            }
            j++;
        }
        answer += (flag ? 1 : 0);
    }

    for (int i = 0; i < N; i++) {
        int bf = board[0][i];
        int flat = 1;
        bool flag = true;
        for (int j = 1; j < N;) {
            if (bf == board[j][i]) {
                flat++;
            } else if (bf + 1 == board[j][i]) {
                if (flat < L) {
                    flag = false;
                    break;
                }
                flat = 1;
                bf = bf + 1;
            } else if (bf - 1 == board[j][i]) {
                if (N < j + L) {
                    flag = false;
                    break;
                }
                int cnt = 0;
                for (int k = j; k < j + L; k++) {
                    if (board[k][i] == bf - 1) {
                        cnt++;
                    }
                }
                if (cnt != L) {
                    flag = false;
                    break;
                }
                flat = 0;
                bf = bf - 1;
                j = j + L - 1;
            } else if (bf != board[j][i]) {
                flag = false;
                break;
            }
            j++;
        }

        answer += (flag ? 1 : 0);
    }

    printf("%d\n", answer);
}