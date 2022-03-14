#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N, M, a, b;
int board[MAX], visited[MAX];

void bfs() {
  queue<pair<int, int>> q;
  q.push(make_pair(1, 0));
  visited[1] = 0;

  while (!q.empty()) {
    int now = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if (board[now] != 0) {
      q.push(make_pair(board[now], cnt));
      continue;
    }
    for (int i = 1; i <= 6; i++) {
      if (now + i >= MAX) {
        continue;
      }
      if (cnt + 1 < visited[now + i]) {
        visited[now + i] = cnt + 1;
        q.push(make_pair(now + i, cnt + 1));
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &a, &b);
    board[a] = b;
  }
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &a, &b);
    board[a] = b;
  }
  for (int i = 1; i < MAX; i++) {
    visited[i] = 2100000000;
  }
  bfs();
  printf("%d\n", visited[MAX - 1]);
}