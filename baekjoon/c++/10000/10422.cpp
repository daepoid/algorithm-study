#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long int dp[5001];

int main() {
  int t, l;
  scanf("%d", &t);
  dp[0] = 1;
  dp[2] = 1;
  for (int i = 3; i < 5001; i++) {
    for (int j = 2; j <= i; j++) {
      dp[i] += dp[j - 2] * dp[i - j];
      dp[i] %= mod;
    }
  }

  while (t-- > 0) {
    scanf("%d", &l);
    printf("%lld\n", dp[l]);
  }
}