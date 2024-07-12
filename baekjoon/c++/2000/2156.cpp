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

int arr[10001];
int dp[10001];

int main() {
  int n, sum;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i + 1]);
  }
  dp[1] = arr[1];
  dp[2] = arr[1] + arr[2];
  for (int i = 3; i < n + 1; i++) {
    sum = max(arr[i] + dp[i - 2], dp[i - 1]);
    sum = max(sum, dp[i - 3] + arr[i] + arr[i - 1]);
    dp[i] = sum;
  }
  printf("%d\n", dp[n]);
}