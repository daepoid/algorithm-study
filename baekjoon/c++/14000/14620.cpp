//
// Created by 박세현 on 2023/04/15.
//


#include "bits/stdc++.h"

#define MAX 11
#define INF 5000
using namespace std;

int N, answer = INF;
int board[MAX][MAX];
int dy[] = {0, 0, -1, 0, 1};
int dx[] = {0, 1, 0, -1, 0};
bool visited[MAX][MAX];

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

bool is_possible(int y, int x) {
    for (int i = 0; i < 5; i++) {
        int newy = y + dy[i];
        int newx = x + dx[i];

        if (!is_valid(newy, newx)) {
            return false;
        }

        if (visited[newy][newx]) {
            return false;
        }
    }

    return !visited[y][x];
}


void dfs(int sum, int cnt) {
    if (cnt == 3) {
        answer = min(answer, sum);
        return;
    }

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (is_possible(i, j)) {
                int newy, newx;
                int temp_sum = 0;
                for (int k = 0; k < 5; k++) {
                    newy = i + dy[k];
                    newx = j + dx[k];
                    temp_sum += board[newy][newx];
                    visited[newy][newx] = true;
                }
                dfs(sum + temp_sum, cnt + 1);
                for (int k = 0; k < 5; k++) {
                    newy = i + dy[k];
                    newx = j + dx[k];
                    visited[newy][newx] = false;
                }
            }
        }
    }
};

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    dfs(0, 0);
    printf("%d\n", answer);
}