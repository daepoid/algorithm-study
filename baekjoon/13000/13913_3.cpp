//
// Created by 박세현 on 2023/04/12.
//


#include "bits/stdc++.h"

#define MAX 200000
using namespace std;

int N, K;
int route[MAX + 4], visited[MAX + 4];
vector<int> v;

int main() {
    scanf("%d %d", &N, &K);
    if (N == K) {
        printf("0\n%d\n", N);
        return 0;
    }
    visited[N] = 1;
    route[N] = -1;

    queue<int> q;
    q.push(N);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto next: {now - 1, now + 1, now * 2}) {
            if (0 <= next && next <= MAX) {
                if (visited[next] == 0) {
                    visited[next] = visited[now] + 1;
                    route[next] = now;
                    q.push(next);
                }
            }
        }
    }
    printf("%d\n", visited[K] - 1);

    int temp = K;
    while (temp != -1) {
        v.push_back(temp);
        temp = route[temp];
    }
    reverse(v.begin(), v.end());
    for (auto val: v) {
        printf("%d ", val);
    }
}