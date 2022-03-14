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

int arr[1001];
int dp[1001];

// NOTE: 구조 이해하기
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i < n + 1; i++) {
    dp[i] = 1;
    for (int j = 0; j < i + 1; j++) {
      if (arr[j] > arr[i]) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
  }
  for (int i = 1; i < n + 1; i++) {
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
}