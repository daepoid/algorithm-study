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

int dp[333], arr[333], n, cnt = 1;

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
  }
  dp[1] = arr[1];
  dp[2] = arr[1] + arr[2];
  for (int i = 3; i < n + 1; i++) {
    dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
  }
  printf("%d\n", dp[n]);
}