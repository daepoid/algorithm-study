#include <bits/stdc++.h>
#define MAX 1030
using namespace std;

int N, M;
int board[MAX][MAX];
int dp[MAX][MAX];
vector<pair<pair<int, int>, pair<int, int>>> cmds;

int calculate(pair<pair<int, int>, pair<int, int>> cmd) {
  int y = cmd.first.first;
  int x = cmd.first.second;
  int yy = cmd.second.first;
  int xx = cmd.second.second;
  return dp[yy][xx] - dp[yy][x - 1] - dp[y - 1][xx] + dp[y - 1][x - 1];
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      scanf("%d", &board[i][j]);
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + board[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    int x1, x2, y1, y2;
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    cmds.push_back({{y1, x1}, {y2, x2}});
  }
  for (int i = 0; i < M; i++) {
    printf("%d\n", calculate(cmds[i]));
  }
}