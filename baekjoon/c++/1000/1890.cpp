#include <bits/stdc++.h>
#define MAX 111
using namespace std;

int N;
int board[MAX][MAX];
long long int dp[MAX][MAX];

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
      if (j + val < N) {
        dp[i][j + val] += dp[i][j];
      }

      // down
      if (i + val < N) {
        dp[i + val][j] += dp[i][j];
      }
    }
  }
  printf("%lld\n", dp[N - 1][N - 1]);
}