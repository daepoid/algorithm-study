#include <bits/stdc++.h>
#define MAX 555
using namespace std;

int N;
int board[MAX][MAX];
int dp[MAX][MAX];

int main() {
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    scanf("%d %d", &board[i][0], &board[i][1]);
  }
  for (int i = 1; i < N + 1; i++) {
    dp[i][i + 1] = board[i][0] * board[i][1] * board[i + 1][1];
  }

  for (int k = 2; k < N + 1; k++) {
    for (int i = 1; i < N + 1 - k; i++) {
      for (int j = i; j < k + i; j++) {
        int res = dp[i][j] + dp[j + 1][k + i] +
                  board[i][0] * board[j][1] * board[k + i][1];
        if (!dp[i][k + i] || dp[i][k + i] > res) {
          dp[i][k + i] = res;
        }
      }
    }
  }
  printf("%d\n", dp[1][N]);
}