//
// Created by SeHyun on 2023-02-06.
//


#include "bits/stdc++.h"

#define MAX 100001
using namespace std;

int N, M, I, W;
vector<int> superior[MAX];
int answer[MAX];

void compliment(int idx) {
    for (int i = 0; i < superior[idx].size(); i++) {
        answer[superior[idx][i]] += answer[idx];
        compliment(superior[idx][i]);
    }
}

int main() {

    scanf("%d %d", &N, &M);
    int temp;
    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &temp);
        superior[temp].push_back(i);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &I, &W);
        answer[I] += W;
    }

    compliment(1);

    for (int i = 1; i < N + 1; i++) {
        if (i != N) {
            printf("%d ", answer[i]);
        } else {
            printf("%d\n", answer[i]);
        }
    }
}