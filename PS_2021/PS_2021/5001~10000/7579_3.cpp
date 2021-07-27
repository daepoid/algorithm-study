#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N, M, sum = 0;
int mem[MAX], cost[MAX];
int dp[MAX][MAX];

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &mem[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &cost[i]);
    sum += cost[i];
  }
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < sum + 1; j++) {
      if (j >= cost[i]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + mem[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  for (int i = 1; i < sum + 1; i++) {
    if (dp[N][i] >= M) {
      printf("%d\n", i - 1);
      break;
    }
  }
  return 0;
}