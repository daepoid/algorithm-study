#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int N, M, answer;
int board[MAX][MAX];
int dp[MAX][MAX];

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

int dfs(int y, int x) {
  if (y == N - 1 && x == M - 1) {
    return 1;
  }
  if (dp[y][x] != -1) {
    return dp[y][x];
  }

  dp[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    int newy = y + dx[i];
    int newx = x + dx[i];
    if (newy >= 0 && newx >= 0 && newy < N && newx < M) {
      if (board[newy][newx] < board[y][x]) {
        dp[y][x] = dp[y][x] + dfs(newy, newx);
      }
    }
  }
  return dp[y][x];
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &board[i][j]);
      dp[i][j] = -1;
    }
  }
  answer = dfs(0, 0);
  printf("%d\n", answer);
  return 0;
}