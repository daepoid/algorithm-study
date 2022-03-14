#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N;
bool board[MAX][MAX], visited[MAX];

int bfs() {
  int cnt = 0;
  queue<int> q;
  q.push(1);
  visited[1] = true;

  while (!q.empty()) {
    int num = q.front();
    q.pop();

    for (int i = 1; i <= N; i++) {
      if (!board[num][i]) {
        continue;
      }
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      q.push(i);
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int cnt;
  scanf("%d", &N);
  scanf("%d", &cnt);
  for (int i = 0; i < cnt; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    board[a][b] = true;
    board[b][a] = true;
  }
  printf("%d\n", bfs());
}