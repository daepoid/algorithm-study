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

int board[501][501];
int dp[501][501];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < i + 1; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = 1; j < n + 1; j++) {
      dp[i][j] = board[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }
  printf("%d\n", dp[1][1]);
}