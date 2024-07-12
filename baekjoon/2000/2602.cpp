//
// Created by SeHyun on 2023-01-31.
//

#include "bits/stdc++.h"

#define DEVIL 0
#define ANGEL 1
#define MAX_LEN 111
#define MAX_MAGIC_LEN 22
using namespace std;

string magic;
string devil, angel;
int dp[MAX_LEN][MAX_MAGIC_LEN][2];

int main() {
    cin >> magic;
    cin >> devil;
    cin >> angel;

    for (int i = 0; i < angel.length(); i++) {
        if (devil[i] == magic[0]) {
            dp[i][0][DEVIL] = 1;
        }
        if (angel[i] == magic[0]) {
            dp[i][0][ANGEL] = 1;
        }
    }

    for (int i = 0; i < angel.length(); i++) {
        for (int j = 1; j < magic.length(); j++) {
            if (devil[i] == magic[j]) {
                int cnt = 0;
                for (int k = 0; k < i; k++) {
                    if (dp[k][j - 1][ANGEL] != 0) {
                        cnt += dp[k][j - 1][ANGEL];
                    }
                    dp[i][j][DEVIL] = cnt;
                }
            }
            if (angel[i] == magic[j]) {
                int cnt = 0;
                for (int k = 0; k < i; k++) {
                    if (dp[k][j - 1][DEVIL] != 0) {
                        cnt += dp[k][j - 1][DEVIL];
                    }
                    dp[i][j][ANGEL] = cnt;
                }
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < angel.length(); i++) {
        answer += dp[i][angel.length() - 1][ANGEL];
        answer += dp[i][devil.length() - 1][DEVIL];
    }
    printf("%d\n", answer);
}