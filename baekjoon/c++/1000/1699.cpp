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

long long int dp[100001];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j * j < i + 1; j++) {
      if (dp[i] == 0) {
        dp[i] = dp[i - j * j] + 1;
      } else {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
  }
  printf("%lld\n", dp[n]);
}