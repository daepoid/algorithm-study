#include <bits/stdc++.h>
using namespace std;

int t[22], p[22], dp[22], n;

int main() {
  int answer = 0;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d %d", &t[i], &p[i]);
  }
  for (int i = 1; i < n + 1; i++) {
    if (i + t[i] <= n + 1) {
      dp[t[i] + i] = max(dp[t[i] + i], dp[i] + p[i]);
      answer = max(answer, dp[t[i] + i]);
    }
    dp[i + 1] = max(dp[i + 1], dp[i]);
    answer = max(answer, dp[i + 1]);
  }
  printf("%d\n", answer);
}