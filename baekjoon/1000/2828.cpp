//
// Created by 박세현 on 2023/04/03.
//


#include "bits/stdc++.h"

#define MAX 11
using namespace std;

int N, M, J;
int basket = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> J;

    int pos;
    int answer = 0;
    for (int i = 0; i < J; i++) {
        cin >> pos;
        if (pos < basket) {
            answer += (basket - pos);
            basket = pos;
        } else if (basket + M <= pos) {
            answer += (pos - (basket + M - 1));
            basket = basket + (pos - (basket + M - 1));
        }
    }

    cout << answer << "\n";
}