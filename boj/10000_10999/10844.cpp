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

int dp[101][10];
int max_num = 1000000000;

int main() {
  int n, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < 10; i++) {
    dp[1][i] = 1;
  }
  for (int i = 2; i < n + 1; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 0) {
        dp[i][j] = dp[i - 1][1];
      } else if (j == 9) {
        dp[i][j] = dp[i - 1][8];
      } else {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) & max_num;
      }
    }
  }
  for (int i = 1; i < 10; i++) {
    sum = (sum + dp[n][i]) % max_num;
  }
  printf("%d\n", sum);
}