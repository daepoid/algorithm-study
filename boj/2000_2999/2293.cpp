#include <bits/stdc++.h>
using namespace std;

int coin[101];
int dp[10001];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &coin[i]);
  }
  dp[0] = 1;

  for (int i = 1; i < n + 1; i++) {
    for (int j = coin[i]; j < k + 1; j++) {
      dp[j] += dp[j - coin[i]];
    }
  }
  printf("%d\n", dp[k]);
}