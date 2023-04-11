//
// Created by 박세현 on 2023/04/04.
//


#include "bits/stdc++.h"

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        int answer = 0;
        for (int j = 5; j < temp + 1; j *= 5) {
            answer += (temp / j);
        }
        cout << answer << "\n";
    }
}