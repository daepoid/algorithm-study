//
// Created by SeHyun on 2023-01-30.
//


#include "bits/stdc++.h"

#define MAX 10001
using namespace std;

int N;
int times[MAX];
vector<int> board[MAX];
int cnt[MAX];
int spend[MAX];

void solution() {
    queue<int> q;
    for (int i = 1; i < N + 1; i++) {
        if (cnt[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        for (int i = 0; i < board[num].size(); i++) {
            int idx = board[num][i];
            spend[idx] = max(spend[idx], spend[num] + times[idx]);
            cnt[idx]--;
            if (cnt[idx] == 0) {
                q.push(idx);
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i < N + 1; i++) {
        int pre_cnt, temp;

        scanf("%d", &times[i]);
        scanf("%d", &pre_cnt);
        spend[i] = times[i];
        for (int j = 0; j < pre_cnt; j++) {
            scanf("%d", &temp);
            board[temp].push_back(i);
            cnt[i]++;
        }
    }

    solution();
    int answer = -1;
    for (int i = 1; i < N + 1; i++) {
        answer = max(answer, spend[i]);
    }

    printf("%d\n", answer);
}