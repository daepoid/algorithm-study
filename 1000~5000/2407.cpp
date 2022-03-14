#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N, M;
long long int dp[MAX][MAX];

long long int combination(int a, int b) {
  if (a == b || b == 0) {
    return 1;
  }
  if (dp[a][b] != 0) {
    return dp[a][b];
  }
  dp[a][b] = combination(a - 1, b) + combination(a - 1, b - 1);
  return dp[a][b];
}

int main() {
  scanf("%d %d", &N, &M);
  printf("%lld\n", combination(N, M));
}