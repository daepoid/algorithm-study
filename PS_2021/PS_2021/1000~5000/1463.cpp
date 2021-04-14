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

int dp[10000001];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i < n + 1; i++) {
    dp[i] = dp[i - 1] + 1;
    if (i % 2 == 0) {
      dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    if (i % 3 == 0) {
      dp[i] = min(dp[i], dp[i / 3] + 1);
    }
  }
  printf("%d\n", dp[n]);
}