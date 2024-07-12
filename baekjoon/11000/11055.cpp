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

int main() {
  int n, temp_sum, max_sum = 0;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i < n + 1; i++) {
    temp_sum = 0;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i] && temp_sum < dp[j]) {
        temp_sum = dp[j];
      }
    }
    dp[i] = temp_sum + arr[i];
    if (max_sum < dp[i]) {
      max_sum = dp[i];
    }
  }
  printf("%d\n", max_sum);
}