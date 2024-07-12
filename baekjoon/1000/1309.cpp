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

int dp[100001][3];
int mod = 9901;

int main() {
  int n;
  scanf("%d", &n);
  dp[1][0] = dp[1][1] = dp[1][2] = 1;
  for (int i = 2; i < n + 1; i++) {
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
  }
  printf("%d\n", (dp[n][0] + dp[n][1] + dp[n][2]) % mod);
}