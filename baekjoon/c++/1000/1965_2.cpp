#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int N, answer = 0;
int board[MAX];
int dp[MAX];

int main() {
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    scanf("%d", &board[i]);
  }

  for (int i = 1; i < N + 1; i++) {
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (board[j] < board[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }
    answer = max(answer, dp[i]);
  }
  printf("%d\n", answer);
}