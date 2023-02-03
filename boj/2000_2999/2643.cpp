//
// Created by SeHyun on 2023-02-01.
//

#include "bits/stdc++.h"

#define MAX_CNT 101
using namespace std;

int N;
int dp[MAX_CNT];
vector<pair<int, int>> v;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back({min(a, b), max(a, b)});
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());

    int answer = 1;
    dp[0] = 1;

    for (int i = 1; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[j].first >= v[i].first && v[j].second >= v[i].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(answer, dp[i]);
    }
    printf("%d\n", answer);
}
