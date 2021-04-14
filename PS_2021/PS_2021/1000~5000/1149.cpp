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

int arr[1001][3];
int dp[1001][3];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
  }
  for (int i = 1; i < n + 1; i++) {
    dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
  }
  printf("%d\n", min(min(dp[n][0], dp[n][1]), dp[n][2]));
}