#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int N, dp[MAX];

int main() {
  scanf("%d", &N);
  for (int i = 2; i < N + 1; i++) {
    dp[i] = dp[i - 1] + 1;
    if (i % 3 == 0) {
      dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    if (i % 2 == 0) {
      dp[i] = min(dp[i], dp[i / 2] + 1);
    }
  }
  printf("%d\n", dp[N]);
}