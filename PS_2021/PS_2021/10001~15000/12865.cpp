#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int weight[MAX];
int value[MAX];
int dp[MAX][100001];

int main() {
  int n, k, w, v;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d %d", &weight[i], &value[i]);
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < k + 1; j++) {
      if (weight[i] <= j) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
}