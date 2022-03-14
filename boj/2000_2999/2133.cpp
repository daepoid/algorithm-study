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

long long int dp[31], sum[31];

int main() {
  int n;
  scanf("%d", &n);
  dp[0] = 1;
  dp[2] = 3;
  sum[0] = 1;
  for (int i = 4; i < n + 1; i += 2) {
    dp[i] = 2;
  }
  for (int i = 2; i < n + 1; i += 2) {
    for (int j = 2; j < i + 1; j += 2) {
      sum[i] += dp[j] * sum[i - j];
    }
  }
  printf("%lld\n", sum[n]);
}