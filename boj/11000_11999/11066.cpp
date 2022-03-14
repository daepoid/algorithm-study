#include <bits/stdc++.h>
#define MAX 501
#define MAX_VAL 2e9
using namespace std;

int dp[MAX][MAX];
int arr[MAX];
int sum[MAX];
int t, k;

int func(int start, int dest) {
  if (start >= dest) {
    return 0;
  }
  if (start + 1 == dest) {
    return sum[dest];
  }
  if (dp[start][dest] < MAX_VAL) {
    return dp[start][dest];
  }
  for (int i = start; i < dest + 1; i++) {
    dp[start][dest] = min(dp[start][dest], func(start, i) + func(i + 1, dest) +
                                               sum[dest] - sum[start - 1]);
  }
  return dp[start][dest];
}

int main() {
  scanf("%d", &t);
  while (t-- > 0) {
    scanf("%d", &k);
    for (int i = 1; i < k; i++) {
      scanf("%d", &arr[i]);
      sum[i] = sum[i - 1] + arr[i];
    }
    for (int i = 1; i < k + 1; i++) {
      for (int j = i; j < k + 1; j++) {
        dp[i][j] = MAX_VAL;
      }
    }
    printf("%d\n", func(1, k));
  }
}