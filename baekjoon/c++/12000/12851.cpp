//
// Created by 박세현 on 2023/04/12.
//

#include "bits/stdc++.h"

#define MAX 200000

using namespace std;
int visited[MAX + 4], cnt[MAX + 4];

int N, M;

int main() {
    scanf("%d %d", &N, &M);
    if (N == M) {
        printf("0\n1\n");
        return 0;
    }

    visited[N] = 1;
    cnt[N] = 1;

    queue<int> q;
    q.push(N);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next: {now - 1, now + 1, now * 2}) {
            if (0 <= next && next <= MAX) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                } else if (visited[next] == visited[now] + 1) {
                    cnt[next] += cnt[now];
                }
            }
        }
    }

    printf("%d\n", visited[M] - 1);
    printf("%d\n", cnt[M]);
}