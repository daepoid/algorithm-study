//
// Created by SeHyun on 2023-01-10.
//

#include "bits/stdc++.h"

#define MAX 129
using namespace std;

int N;
bool board[MAX][MAX];
int white_count = 0, blue_count = 0;

void check(int y, int x, int size) {
    bool white = true, blue = true;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (board[i][j]) {
                white = false;
            } else {
                blue = false;
            }
        }
    }

    if (white) {
        white_count++;
    } else if (blue) {
        blue_count++;
    } else {
        check(y, x, size / 2);
        check(y, x + size / 2, size / 2);
        check(y + size / 2, x, size / 2);
        check(y + size / 2, x + size / 2, size / 2);
    }
}

int main() {
    int temp;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &temp);
            board[i][j] = temp == 1;
        }
    }
    check(0, 0, N);
    printf("%d\n%d\n", white_count, blue_count);
}