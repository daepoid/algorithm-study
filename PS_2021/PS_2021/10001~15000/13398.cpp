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

int arr[100001];
int dp[100001][2];

int main() {
  int n, ans, sum = 0;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }
  ans = arr[1];
  dp[0][0] = dp[0][1] = -1001;
  for (int i = 1; i < n + 1; i++) {
    dp[i][0] = dp[i][1] = arr[i];
    dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
    ans = max(ans, max(dp[i][0], dp[i][1]));
  }
  printf("%d\n", ans);
}