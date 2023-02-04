//
// Created by SeHyun on 2023-02-05.
//


#include "bits/stdc++.h"

#define MAX 101
using namespace std;


string str1, str2, str3;
int dp[MAX][MAX][MAX];

int main() {
    cin >> str1 >> str2 >> str3;

    for (int i = 0; i < str1.length(); i++) {
        for (int j = 0; j < str2.length(); j++) {
            for (int k = 0; k < str3.length(); k++) {
                if (str1[i] == str2[j] && str2[j] == str3[k]) {
                    dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
                } else {
                    dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k], max(dp[i + 1][j][k + 1], dp[i][j + 1][k + 1]));
                }
            }
        }
    }
    printf("%d\n", dp[str1.length()][str2.length()][str3.length()]);
}