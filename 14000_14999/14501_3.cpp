#include <bits/stdc++.h>
#define MAX 16
using namespace std;

int N, answer = 0;
int T[MAX], P[MAX], dp[MAX];

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &T[i], &P[i]);
  }

  for (int i = 1; i < N + 1; i++) {
    if (i + T[i] <= N + 1) {
      dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
      answer = max(answer, dp[i + T[i]]);
    }
    dp[i + 1] = max(dp[i + 1], dp[i]);
    answer = max(answer, dp[i + 1]);
  }
  printf("%d\n", answer);
}