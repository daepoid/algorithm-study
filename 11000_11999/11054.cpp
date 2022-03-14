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
int dp1[1001], dp2[1001];

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i < n + 1; i++) {
    dp1[i] = 1;
    dp2[n - i + 1] = 1;
    for (int j = 0; j < i + 1; j++) {
      if (arr[j] < arr[i]) {
        dp1[i] = max(dp1[j] + 1, dp1[i]);
      }
      if (arr[n - j + 1] < arr[n - i + 1]) {
        dp2[n - i + 1] = max(dp2[n - j + 1] + 1, dp2[n - i + 1]);
      }
    }
  }
  for (int i = 1; i < n + 1; i++) {
    ans = max(ans, dp1[i] + dp2[i]);
  }
  printf("%d\n", ans - 1);
}