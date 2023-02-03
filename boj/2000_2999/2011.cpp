//
// Created by SeHyun on 2023-01-17.
//

#include "bits/stdc++.h"

#define MAX 5001
#define MOD 1000000
using namespace std;

string encoded;
int dp[MAX];

int main() {
    cin >> encoded;
    if (encoded[0] == '0') {
        cout << 0 << "\n";
        return 0;
    }
    dp[0] = 1;
    for (int i = 1; i < encoded.length() + 1; i++) {
        if (encoded[i - 1] != '0') {
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
        }

        if (i == 1) {
            continue;
        }

        if ("10" <= encoded.substr(i - 2, 2) && encoded.substr(i - 2, 2) <= "26") {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }
    cout << dp[encoded.length()] << "\n";
    return 0;
}