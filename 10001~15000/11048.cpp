#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];
int arr[MAX][MAX];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      dp[i][j] =
          max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + arr[i][j];
    }
  }
  printf("%d\n", dp[n][m]);
}