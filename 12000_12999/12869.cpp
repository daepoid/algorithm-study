#include <bits/stdc++.h>
#define MAX 61
using namespace std;

int dp[MAX][MAX][MAX], scv[3];

int func(int a, int b, int c) {
  if (a < 0) {
    return func(0, b, c);
  }
  if (b < 0) {
    return func(a, 0, c);
  }
  if (c < 0) {
    return func(a, b, 0);
  }
  if (a == 0 && b == 0 && c == 0) {
    return 0;
  }
  if (dp[a][b][c] != -1) {
    return dp[a][b][c];
  }

  dp[a][b][c] = 987654321;
  dp[a][b][c] = min(dp[a][b][c], func(a - 9, b - 3, c - 1) + 1);
  dp[a][b][c] = min(dp[a][b][c], func(a - 9, b - 1, c - 3) + 1);
  dp[a][b][c] = min(dp[a][b][c], func(a - 3, b - 9, c - 1) + 1);
  dp[a][b][c] = min(dp[a][b][c], func(a - 3, b - 1, c - 9) + 1);
  dp[a][b][c] = min(dp[a][b][c], func(a - 1, b - 9, c - 3) + 1);
  dp[a][b][c] = min(dp[a][b][c], func(a - 1, b - 3, c - 9) + 1);

  return dp[a][b][c];
}

int main() {
  int n;
  scanf("%d", &n);
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    scanf("%d", &scv[i]);
  }
  printf("%d\n", func(scv[0], scv[1], scv[2]));
}