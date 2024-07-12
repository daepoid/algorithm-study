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

int n, arr[1111], dp[1111], min_num, max_num;

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i < n + 1; i++) {
    min_num = 0;
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        if (min_num < dp[j]) {
          min_num = dp[j];
        }
      }
    }
    dp[i] = min_num + 1;
    max_num = max(max_num, dp[i]);
  }
  printf("%d\n", max_num);
}