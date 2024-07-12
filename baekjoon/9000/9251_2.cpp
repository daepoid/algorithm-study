//
// Created by SeHyun on 2023-02-04.
//


#include "bits/stdc++.h"

#define MAX 1001
using namespace std;

string str1, str2;
int dp[MAX][MAX];

int main() {
    cin >> str1 >> str2;

    for (int i = 0; i < str1.length(); i++) {
        for (int j = 0; j < str2.length(); j++) {
            if (str1[i] == str2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    printf("%d\n", dp[str1.length()][str2.length()]);
}