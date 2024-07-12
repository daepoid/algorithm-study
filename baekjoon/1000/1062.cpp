//
// Created by 박세현 on 2023/04/26.
//

#include "bits/stdc++.h"

#define MAX 51
using namespace std;

int N, K, answer = 0;
string arr[MAX];
bool alpha[26];

int is_readable() {
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        bool readable = true;
        for (int j = 0; j < arr[i].length(); j++) {
            if (!alpha[arr[i][j] - 'a']) {
                readable = false;
                break;
            }
        }
        cnt += (readable ? 1 : 0);
    }
    return cnt;
}

void dfs(int idx, int cnt) {
    if (cnt == K) {
        answer = max(answer, is_readable());
        return;
    }

    for (int i = idx; i < 26; i++) {
        if (!alpha[i]) {
            alpha[i] = true;
            dfs(i, cnt + 1);
            alpha[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string temp = "antic";

    cin >> N >> K;

    K -= 5;
    if (K < 0) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 0; i < temp.length(); i++) {
        alpha[temp[i] - 'a'] = true;
    }

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dfs(0, 0);
    cout << answer << "\n";
}