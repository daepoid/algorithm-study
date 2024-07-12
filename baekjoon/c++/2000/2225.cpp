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

long long int dp[222][222];
long long int mod = 1000000000;

int main() {
  long long int n, k;
  scanf("%lld %lld", &n, &k);
  for (int i = 0; i < n + 1; i++) {
    dp[1][i] = 1;
  }
  for (int i = 2; i < k + 1; i++) {
    for (int j = 0; j < n + 1; j++) {
      for (int l = 0; l < j + 1; l++) {
        dp[i][j] += dp[i - 1][l];
      }
      dp[i][j] %= mod;
    }
  }
  printf("%lld\n", dp[k][n]);
}