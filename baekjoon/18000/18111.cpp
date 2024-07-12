//
// Created by SeHyun on 2023-01-09.
//

#include "bits/stdc++.h"

#define MAX 501
using namespace std;

int N, M, B, answer_time = MAX * MAX * 2 * 256, answer_height = 0;
int board[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> B;
    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }


    for (int h = 0; h <= 256; h++) {
        int remove_block = 0, build_block = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int diff = board[i][j] - h;
                if (diff < 0) {
                    build_block -= diff;
                } else if (diff > 0) {
                    remove_block += diff;
                }
            }
        }

        if (build_block <= remove_block + B && build_block + remove_block * 2 <= answer_time) {
            answer_time = build_block + remove_block * 2;
            answer_height = h;
        }
    }
    cout << answer_time << " " << answer_height << "\n";
}
