//
// Created by 박세현 on 2023/04/03.
//


#include "bits/stdc++.h"

#define MAX 65
using namespace std;

int N;
string board[MAX];

void solution(int y, int x, int len) {
    bool black = true, white = true;
    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            if (black && board[i][j] == '0') {
                black = false;
            } else if (white && board[i][j] == '1') {
                white = false;
            }
            if (!black && !white) {
                break;
            }
        }
    }

    if (black) {
        cout << "1";
    } else if (white) {
        cout << "0";
    } else {
        cout << "(";
        solution(y, x, len / 2);
        solution(y, x + len / 2, len / 2);
        solution(y + len / 2, x, len / 2);
        solution(y + len / 2, x + len / 2, len / 2);
        cout << ")";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string line;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    solution(0, 0, N);
}