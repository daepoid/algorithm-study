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

// NOTE: 이해 없는 상태

int n, a, b;
int t[20], p[20], dp[20], ans = 0;

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d %d", &t[i], &p[i]);
  }

  for (int i = 1; i < n + 1; i++) {
    if (i + t[i] <= n + 1) {
      dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
      ans = max(ans, dp[i + t[i]]);
    }
    dp[i + 1] = max(dp[i + 1], dp[i]);
    ans = max(ans, dp[i + 1]);
  }
  printf("%d\n", ans);
}