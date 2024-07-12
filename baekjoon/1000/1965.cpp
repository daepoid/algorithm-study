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

int main() {
  int n, arr[1001], dp[1001], max = 0;
  memset(arr, 0, sizeof(arr));
  memset(dp, 0, sizeof(dp));
  scanf("%d", &n);

  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
  }

  for (int i = 1; i < n + 1; i++) {
    dp[i] = 1;

    for (int j = 1; j < i; j++) {
      if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }

    if (max < dp[i]) {
      max = dp[i];
    }
  }
  printf("%d\n", max);
}