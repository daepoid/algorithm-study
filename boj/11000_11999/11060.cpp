#include <bits/stdc++.h>
#define MAX 1001
#define INF 1000 * 100 + 1
using namespace std;

int arr[MAX];
int dp[MAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
    dp[i] = INF;
  }
  dp[1] = 0;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < arr[i] + 1 && i + j < n + 1; j++) {
      dp[i + j] = min(dp[i] + 1, dp[i + j]);
    }
  }
  if (dp[n] == INF) {
    printf("-1\n");
  } else {
    printf("%d\n", dp[n]);
  }
}