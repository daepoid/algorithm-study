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

int dp[1001];

int main() {
  int n;
  scanf("%d", &n);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i < n + 1; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
  }
  printf("%d\n", dp[n]);
}