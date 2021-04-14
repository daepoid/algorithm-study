#include <bits/stdc++.h>
#define MAX 2001
using namespace std;

int n, m;
int arr[MAX];
int dp[MAX][MAX];

int main() {
  int a, b;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i < n + 1; i++) {
    dp[1][i] = 1;
    if (arr[i - 1] == arr[i]) {
      dp[2][i - 1] = 1;
    }
  }

  for (int i = 3; i < n + 1; i++) {
    for (int j = 1; j < n - i + 2; j++) {
      if (arr[j] == arr[j + i - 1] && dp[i - 2][j + 1] == 1) {
        dp[i][j] = 1;
      }
    }
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", dp[b - a + 1][a]);
  }
}