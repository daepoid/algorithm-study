#include <bits/stdc++.h>
#define MAX 10000001
#define INF 2100000000
using namespace std;

int N;
int dp[MAX][2];

int main() {
  scanf("%d", &N);

  for (int i = 1; i < N; i++) {
    if (i * 3 < MAX) {
      if (dp[i * 3][0] == 0 || dp[i * 3][0] > dp[i][0] + 1) {
        dp[i * 3][0] = dp[i][0] + 1;
        dp[i * 3][1] = i;
      }
    }
    if (i * 2 < MAX) {
      if (dp[i * 2][0] == 0 || dp[i * 2][0] > dp[i][0] + 1) {
        dp[i * 2][0] = dp[i][0] + 1;
        dp[i * 2][1] = i;
      }
    }
    if (i + 1 < MAX) {
      if (dp[i + 1][0] == 0 || dp[i + 1][0] > dp[i][0] + 1) {
        dp[i + 1][0] = dp[i][0] + 1;
        dp[i + 1][1] = i;
      }
    }
  }

  printf("%d\n", dp[N][0]);

  int idx = N;
  while (idx > 0) {
    if (idx == 1) {
      printf("%d\n", idx);
      break;
    }
    printf("%d ", idx);
    idx = dp[idx][1];
  }
  return 0;
}