#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int dp[MAX + 1][MAX + 1][MAX + 1];

int func(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) {
    return 1;
  }
  if (a > MAX || b > MAX || c > MAX) {
    dp[MAX][MAX][MAX] = func(MAX, MAX, MAX);
    return dp[MAX][MAX][MAX];
  }

  if (dp[a][b][c] != 0) {
    return dp[a][b][c];
  }

  if (a < b && b < c) {
    dp[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) + func(a, b - 1, c);
  }

  dp[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) +
                func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
  return dp[a][b][c];
}

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  while (!(a == -1 && b == -1 && c == -1)) {
    int answer = func(a, b, c);
    printf("w(%d, %d, %d) = %d\n", a, b, c, answer);
    scanf("%d %d %d", &a, &b, &c);
  }
}