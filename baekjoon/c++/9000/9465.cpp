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

int dp[2][100001];
int post[2][100001];

int main() {
  int t, n;
  scanf("%d", &t);
  while (t-- > 0) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &post[0][i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &post[1][i]);
    }
    dp[0][0] = post[0][0];
    dp[1][0] = post[1][0];
    dp[0][1] = post[0][1] + post[1][0];
    dp[1][1] = post[1][1] + post[0][0];
    for (int i = 2; i < n; i++) {
      dp[0][i] = post[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
      dp[1][i] = post[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
    }
    printf("%d\n", max(dp[0][n - 1], dp[1][n - 1]));
  }
}