#include <bits/stdc++.h>
#define ARRMAX 111
#define MAX 21
using namespace std;

int N, nums[ARRMAX];
long long int dp[ARRMAX][MAX]; // dp[A번째, 생성된 값이 B]

void calculate(int nth) {
  for (int i = 0; i < MAX; i++) {
    if (dp[nth - 1][i] == 0) {
      continue;
    }

    if (i + nums[nth] < MAX) {
      dp[nth][i + nums[nth]] += dp[nth - 1][i];
    }
    if (i - nums[nth] >= 0) {
      dp[nth][i - nums[nth]] += dp[nth - 1][i];
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    scanf("%d", &nums[i]);
  }

  dp[1][nums[1]] = 1;

  for (int i = 2; i < N; i++) {
    calculate(i);
  }
  printf("%lld\n", dp[N - 1][nums[N]]);
}