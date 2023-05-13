//
// Created by 박세현 on 2023/05/11.
//


#include "bits/stdc++.h"

using namespace std;

int M, num, S;
string cmd;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> num;
            S |= (1 << num);
        } else if (cmd == "remove") {
            cin >> num;
            S &= ~(1 << num);
        } else if (cmd == "check") {
            cin >> num;
            printf("%d\n", (S & (1 << num)) == 0 ? 0 : 1);
        } else if (cmd == "toggle") {
            cin >> num;
            S ^= (1 << num);
        } else if (cmd == "all") {
            S = (1 << 21) - 1;
        } else if (cmd == "empty") {
            S = 0;
        }
    }
}