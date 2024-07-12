#include <bits/stdc++.h>
using namespace std;
int n, k;
int coin[101];
int dp[10001];

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &coin[i]);
  }
  for (int i = 0; i < k + 1; i++) {
    dp[i] = 20000;
  }

  dp[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    for (int j = coin[i]; j <= k; j++) {
      dp[j] = min(dp[j], dp[j - coin[i]] + 1);
    }
  }
  if (dp[k] == 20000) {
    printf("-1\n");
  } else {
    printf("%d\n", dp[k]);
  }
}