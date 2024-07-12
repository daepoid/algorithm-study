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

int dp[1001][10];
int mod = 10007;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 10; i++) {
    dp[0][i] = 1;
  }

  for (int i = 1; i < n + 2; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < j + 1; k++) {
        dp[i][j] += dp[i - 1][k];
        dp[i][j] %= mod;
      }
    }
  }
  printf("%d\n", dp[n][9]);
}