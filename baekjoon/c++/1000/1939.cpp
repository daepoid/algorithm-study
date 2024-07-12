//
// Created by SeHyun on 2023-01-09.
//


#include "bits/stdc++.h"

#define MAX 10001
using namespace std;

int N, M;
int low = 0, high = 0;
bool visited[MAX];
vector<pair<int, int>> board[MAX];

bool bfs(int start, int end, int cost) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == end) {
            return true;
        }

        for (int i = 0; i < board[curr].size(); i++) {
            int next = board[curr][i].first;
            int next_cost = board[curr][i].second;

            if (visited[next]) {
                continue;
            }

            if (cost > next_cost) {
                continue;
            }
            visited[next] = true;
            q.push(next);
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &N, &M);
    int a, b, c;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        board[a].push_back({b, c});
        board[b].push_back({a, c});
        high = max(high, c);
    }
    scanf("%d %d", &a, &b);

    while (low <= high) {
        memset(visited, false, sizeof(visited));
        int mid = (low + high) / 2;
        if (bfs(a, b, mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d\n", high);
}