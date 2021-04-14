#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int board[111];
int visited[111];

void bfs() {
  queue<pair<int, int>> q;
  q.push(make_pair(1, 0));
  visited[1] = 0;
  while (!q.empty()) {
    int pos = q.front().first;
    int cnt = q.front().second;
    int newpos, newcnt;
    q.pop();

    if (board[pos] != 0) {
      newpos = board[pos];
      q.push(make_pair(newpos, cnt));
      continue;
    }

    for (int i = 1; i < 7; i++) {
      newpos = pos + i;
      newcnt = cnt + 1;

      if (newpos > 100) {
        continue;
      }

      if (newcnt < visited[newpos]) {
        visited[newpos] = newcnt;
        q.push(make_pair(newpos, newcnt));
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  memset(visited, 1000000000, sizeof(visited));
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    board[a] = b;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    board[a] = b;
  }
  for (int i = 1; i < 101; i++) {
    visited[i] = 2100000000;
  }
  bfs();
  printf("%d\n", visited[100]);
}