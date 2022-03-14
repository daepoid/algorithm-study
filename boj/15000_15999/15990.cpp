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

long long int dp[100001][4];
long long int mod = 1000000009;
int main() {
  int tc, n;
  scanf("%d", &tc);
  dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
  for (int i = 4; i < 100001; i++) {
    if (i - 1 >= 0) {
      dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
    }
    if (i - 2 >= 0) {
      dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
    }
    if (i - 3 >= 0) {
      dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
    }
  }
  while (tc-- > 0) {
    scanf("%d", &n);
    printf("%d\n", (dp[n][1] + dp[n][2] + dp[n][3]) % mod);
  }
}