#include <bits/stdc++.h>
#define MAX 101
using namespace std;

bool dp[MAX][1001];
int arr[MAX];

int main() {
  int n, s, m;
  scanf("%d %d %d", &n, &s, &m);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
  }
  if (s + arr[1] <= m) {
    dp[1][s + arr[1]] = true;
  }
  if (s - arr[1] >= 0) {
    dp[1][s - arr[1]] = true;
  }

  for (int i = 2; i < n + 1; i++) {
    for (int j = 0; j < m + 1; j++) {
      if (dp[i - 1][j]) {
        if (j + arr[i] <= m) {
          dp[i][j + arr[i]] = true;
        }
        if (j - arr[i] >= 0) {
          dp[i][j - arr[i]] = true;
        }
      }
    }
  }

  for (int i = m; i >= 0; i--) {
    if (dp[n][i]) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
}