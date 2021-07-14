#include <bits/stdc++.h>
#define MAX 111
#define MAX_WEIGHT 111111
using namespace std;

int N, K;
int W[MAX], V[MAX];
int dp[MAX][MAX_WEIGHT];

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i < N + 1; i++) {
    scanf("%d %d", &W[i], &V[i]);
  }

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < K + 1; j++) {
      if (j >= W[i]) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  printf("%d\n", dp[N][K]);
}