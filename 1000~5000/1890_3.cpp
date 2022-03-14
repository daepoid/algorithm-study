#include <bits/stdc++.h>
#define MAX 111
using namespace std;

int N;
int board[MAX][MAX];
long long int dp[MAX][MAX];

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) {
        continue;
      }

      int val = board[i][j];
      // right
      if (isvalid(i, j + val)) {
        dp[i][j + val] += dp[i][j];
      } else {
        if (i == N - 1 && N - 1 <= j + val) {
          dp[N - 1][N - 1] += dp[i][j];
        }
      }

      // down
      if (isvalid(i + val, j)) {
        dp[i + val][j] += dp[i][j];
      } else {
        if (j == N - 1 && N - 1 <= i + val) {
          dp[N - 1][N - 1] += dp[i][j];
        }
      }
    }
  }
  printf("%d\n", dp[N - 1][N - 1]);
}