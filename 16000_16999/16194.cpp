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

int arr[10001], dp[10001], n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
    dp[i] = 2100000000;
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = i; j < n + 1; j++) {
      dp[j] = min(dp[j], dp[j - i] + arr[i]);
    }
  }
  printf("%d\n", dp[n]);
}