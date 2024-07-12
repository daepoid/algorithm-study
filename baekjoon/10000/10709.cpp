//
// Created by 박세현 on 2023/04/04.
//


#include "bits/stdc++.h"

#define MAX 101
using namespace std;

int H, W;
string board[MAX];
int answer[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(answer[0], answer[MAX - 1] + (MAX - 1), -1);
    cin >> H >> W;
    string temp;
    for (int i = 0; i < H; i++) {
        cin >> board[i];
        int t = 0;
        for (int j = 0; j < W; j++) {
            if (t == 0 && board[i][j] == '.') {
                answer[i][j] = -1;
            } else if (board[i][j] == 'c') {
                answer[i][j] = 0;
                t = 1;
            } else {
                answer[i][j] = t++;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}