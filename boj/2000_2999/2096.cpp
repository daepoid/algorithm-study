#include <bits/stdc++.h>
#define MAX 10
using namespace std;

int N;
int board[MAX][5];
int dp[MAX][5];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= 3; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  dp[0][1] = board[0][1];
  dp[0][2] = board[0][2];
  dp[0][3] = board[0][3];

  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= 3; j++) {
      int temp = dp[i + 1][j];
      temp = max(temp, dp[i][j - 1] + board[i + 1][j]);
      temp = max(temp, dp[i][j] + board[i + 1][j]);
      temp = max(temp, dp[i][j + 1] + board[i + 1][j]);
      dp[i + 1][j] = temp;
    }
  }
  printf("%d\n", dp[N][2]);
}