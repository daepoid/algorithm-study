#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N, M, sum = 0;
int mem[MAX], cost[MAX];
int dp[MAX * MAX];

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &mem[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &cost[i]);
    sum += cost[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = sum; j >= cost[i]; j--) {
      dp[j] = max(dp[j], dp[j - cost[i]] + mem[i]);
    }
  }
  int i;
  for (i = 0; i < sum, dp[i] < M; i++) {
  }
  printf("%d\n", i);
  return 0;
}