#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

int N, K;
int L[MAX];
int dp[MAX][2];

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i < N; i++) {
    scanf("%d", &L[i]);
  }
  dp[1][0] = 1;
  dp[1][1] = 1;

  for (int i = 1; i < N; i++) {
    int sum = 0;
    for (int j = i; j < N; j++) {
      sum += L[j];
      if (sum > K) {
        dp[j + 1][1] = max(dp[j + 1][1], dp[i][0] + 1);
        break;
      }
      dp[j + 1][0] = max(dp[j + 1][0], dp[i][0] + 1);
      dp[j + 1][1] = max(dp[j + 1][1], dp[i][1] + 1);
    }
  }
  printf("%d\n", max(dp[N][0], dp[N][1]));
}