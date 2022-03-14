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

long long int dp[91][2];

int main() {
  long long int n, sum = 0;
  scanf("%lld", &n);
  dp[1][0] = 0;
  dp[1][1] = 1;
  for (long long int i = 2; i < n + 1; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
  }
  printf("%lld\n", dp[n][0] + dp[n][1]);
}