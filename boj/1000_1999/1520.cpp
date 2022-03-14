#include <bits/stdc++.h>
#define MAX 555
using namespace std;

int M, N;
int board[MAX][MAX], dp[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < M && 0 <= newx && newx < N;
}

int dfs(int y, int x) {
  if (y == M - 1 && x == N - 1) {
    return 1;
  }
  if (dp[y][x] != -1) {
    return dp[y][x];
  }

  dp[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (!isvalid(newy, newx)) {
      continue;
    }
    if (board[y][x] <= board[newy][newx]) {
      continue;
    }
    dp[y][x] += dfs(newy, newx);
  }
  return dp[y][x];
}

int main() {
  scanf("%d %d", &M, &N);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
      dp[i][j] = -1;
    }
  }
  printf("%d\n", dfs(0, 0));
}