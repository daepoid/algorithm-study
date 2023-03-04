//
// Created by SeHyun on 2023-02-22.
//


#include "bits/stdc++.h"

#define MAX 501
using namespace std;

int N;
int times[MAX], cnt[MAX], dp[MAX];
vector<int> v[MAX];

void solution() {
    queue<int> q;
    for (int i = 1; i < N + 1; i++) {
        if (cnt[i] == 0) {
            q.push(i);
            dp[i] = times[i];
        }
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        for (int i = 0; i < v[idx].size(); i++) {
            int next = v[idx][i];
            cnt[next]--;
            if (cnt[next] == 0) {
                q.push(next);
            }
            dp[next] = max(dp[next], dp[idx] + times[next]);
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &times[i]);
        int temp;
        while (true) {
            scanf("%d", &temp);
            if (temp == -1) {
                break;
            }
            v[temp].push_back(i);
            cnt[i]++;
        }
    }

    solution();

    for (int i = 1; i < N + 1; i++) {
        printf("%d\n", dp[i]);
    }
}