#include <bits/stdc++.h>
#define MAX 11
using namespace std;

int T, N;
int dp[MAX];

int main() {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i = 4; i < MAX; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }
  scanf("%d", &T);
  while (T-- > 0) {
    scanf("%d", &N);
    printf("%d\n", dp[N]);
  }
}