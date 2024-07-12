#include <bits/stdc++.h>
#define MAX 101
#define MAXWEIGHT 100100
using namespace std;

int N, K;
int weight[MAX], values[MAX], dp[MAX][MAXWEIGHT];

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i < N + 1; i++) {
    scanf("%d %d", &weight[i], &values[i]);
  }
  
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < K + 1; j++) {
      if (j >= weight[i]) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + values[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  printf("%d\n", dp[N][K]);
}