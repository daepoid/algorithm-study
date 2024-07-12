#include <bits/stdc++.h>
#define MAX 55
using namespace std;

int T;
int M, N, K;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool board[MAX][MAX], visited[MAX][MAX];

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

void bfs(int a, int b) {
  queue<pair<int, int>> q;
  q.push({a, b});
  visited[a][b] = true;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      }
      if (!board[newy][newx]) {
        continue;
      }
      if (visited[newy][newx]) {
        continue;
      }
      q.push({newy, newx});
      visited[newy][newx] = true;
    }
  }
}

int main() {
  scanf("%d", &T);
  while (T-- > 0) {
    int cnt = 0;
    memset(board, false, sizeof(board));
    memset(visited, false, sizeof(visited));
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < K; i++) {
      int X, Y;
      scanf("%d %d", &X, &Y);
      board[Y][X] = true;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board[i][j] && !visited[i][j]) {
          bfs(i, j);
          cnt++;
        }
      }
    }
    printf("%d\n", cnt);
  }
}