#include <bits/stdc++.h>
#define MAX 555
using namespace std;

int N, answer = 0;
int board[MAX][MAX], dp[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

int dfs(int y, int x) {
  if (dp[y][x] != 0) {
    return dp[y][x];
  }
  dp[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (!isvalid(newy, newx)) {
      continue;
    }
    if (board[y][x] >= board[newy][newx]) {
      continue;
    }
    dp[y][x] = max(dp[y][x], dfs(newy, newx) + 1);
  }
  return dp[y][x];
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      answer = max(answer, dfs(i, j));
    }
  }
  printf("%d\n", answer);
}