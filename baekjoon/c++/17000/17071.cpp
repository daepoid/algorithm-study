#include <bits/stdc++.h>
#define MAX 500000
using namespace std;

int N, K;
int visited[MAX + 1][2];

int getsum(int num) { return num * (num + 1) / 2; }

void bfs() {
  memset(visited, -1, sizeof(visited));
  queue<pair<int, int>> q;
  q.push(make_pair(N, 0));

  while (!q.empty()) {
    int pos = q.front().first;
    int time = q.front().second;
    q.pop();

    if (pos < 0 || MAX < pos) {
      continue;
    }
    if (visited[pos][time % 2] != -1) {
      continue;
    }
    visited[pos][time % 2] = time;
    q.push(make_pair(pos * 2, time + 1));
    q.push(make_pair(pos + 1, time + 1));
    q.push(make_pair(pos - 1, time + 1));
  }
}

void move_brother() {
  for (int i = 0; i < MAX + 1; i++) {
    int pos = K + getsum(i);
    if (pos > MAX) {
      break;
    }
    if (visited[pos][i % 2] != -1 && visited[pos][i % 2] <= i) {
      printf("%d\n", i);
      return;
    }
  }
  printf("-1\n");
  return;
}

int main() {
  int time = 0;
  scanf("%d %d", &N, &K);
  bfs();
  move_brother();
}