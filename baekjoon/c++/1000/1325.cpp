//
// Created by 박세현 on 2023/04/05.
//

#include "bits/stdc++.h"

#define MAX 10001
using namespace std;

int N, M;
int max_cnt = 0;
bool visited[MAX];
vector<int> answer;
vector<int> board[MAX];

void bfs(int st) {
    queue<int> q;
    q.push(st);
    memset(visited, false, sizeof(visited));
    visited[st] = true;
    int cnt = 1;

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        for (int i = 0; i < board[num].size(); i++) {
            int next = board[num][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }

    if (max_cnt == cnt) {
        answer.push_back(st);
    } else if (max_cnt < cnt) {
        max_cnt = cnt;
        answer.clear();
        answer.push_back(st);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int A, B;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        board[B].push_back(A);
    }

    for (int i = 1; i < N + 1; i++) {
        bfs(i);
    }
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
        printf("%d ", answer[i]);
    }
}