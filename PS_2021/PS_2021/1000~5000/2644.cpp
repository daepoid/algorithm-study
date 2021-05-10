#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N, M, num_first, num_second;
bool board[MAX][MAX], visited[MAX];

int bfs(int a, int b) {
  queue<pair<int, int>> q;
  q.push({a, 0});
  visited[a] = true;

  while (!q.empty()) {
    int num = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if (num == b) {
      return cnt;
    }
    for (int i = 1; i <= N; i++) {
      if (!board[num][i]) {
        continue;
      }
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      q.push({i, cnt + 1});
    }
  }
  return -1;
}

int main() {
  scanf("%d", &N);
  scanf("%d %d", &num_first, &num_second);
  scanf("%d", &M);
  int a, b;
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &a, &b);
    board[a][b] = true;
    board[b][a] = true;
  }
  printf("%d\n", bfs(num_first, num_second));
}