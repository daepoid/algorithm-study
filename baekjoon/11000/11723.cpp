//
// Created by SeHyun on 2023-01-09.
//


#include "bits/stdc++.h"

using namespace std;

int M;
bool arr[21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    string cmd;
    int val;
    for (int i = 0; i < M; i++) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> val;
            arr[val] = true;
        } else if (cmd == "remove") {
            cin >> val;
            arr[val] = false;
        } else if (cmd == "check") {
            cin >> val;
            cout << (arr[val] ? 1 : 0) << "\n";
        } else if (cmd == "toggle") {
            cin >> val;
            arr[val] = !arr[val];
        } else if (cmd == "all") {
            memset(arr, true, sizeof(arr));
        } else if (cmd == "empty") {
            memset(arr, false, sizeof(arr));
        }
    }
}