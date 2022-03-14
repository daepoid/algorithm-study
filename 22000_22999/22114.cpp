#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

int N, K, answer = 1;
int L[MAX], dp[MAX][2];

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i < N; i++) {
    scanf("%d", &L[i]);
  }
  dp[1][0] = 1;
  dp[1][1] = 1;

  for (int i = 1; i < N; i++) {
    if (L[i] <= K) {
      dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + 1);
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + 1);
    } else {
      dp[i + 1][0] = 1;
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + 1);
    }
    answer = max(answer, dp[i + 1][0]);
    answer = max(answer, dp[i + 1][1]);
  }
  printf("%d\n", answer);
}