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
      int d = i + val;
      int r = j + val;

      if (d < N) {
        dp[d][j] += dp[i][j];
      }
      if (r < N) {
        dp[i][r] += dp[i][j];
      }
    }
  }
  printf("%lld\n", dp[N - 1][N - 1]);
}