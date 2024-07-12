#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

long long int mod = 1000000009;
long long int dp[1000001][4];

int main() {
  long long int t, n;
  scanf("%lld", &t);
  dp[1][0] = dp[1][1] = dp[2][1] = dp[2][2] = dp[2][3] = dp[3][3] = 1;
  dp[2][0] = dp[1][3] = 2;
  dp[3][0] = 4;
  while (t-- > 0) {
    scanf("%lld", &n);
    if (dp[n][0] != 0) {
      printf("%lld\n", dp[n][0]);
      continue;
    }
    for (long long int i = 4; i < n + 1; i++) {
      dp[i][1] = dp[i - 1][0];
      dp[i][2] = dp[i - 2][0];
      dp[i][3] = dp[i - 3][0];
      dp[i][0] = (dp[i][1] + dp[i][2] + dp[i][3]) % mod;
    }
    printf("%lld\n", dp[n][0]);
  }
}