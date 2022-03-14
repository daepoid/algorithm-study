#include <bits/stdc++.h>
using namespace std;

long long int dp[101];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < 6; i++) {
    dp[i] = i;
  }

  for (int i = 6; i < n + 1; i++) {
    dp[i] = max(max(dp[i - 1] + 1, dp[i - 3] * 2),
                max(dp[i - 4] * 3, dp[i - 5] * 4));
  }
  printf("%lld\n", dp[n]);
}