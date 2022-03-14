#include <bits/stdc++.h>
#define MAX 111
using namespace std;

int arr[MAX], n;
long long int dp[111][30];

long long int func(int x, int result) {
  if (x == n) {
    if (result == arr[x]) {
      dp[x][result] = 1;
    } else {
      dp[x][result] = 0;
    }
    return dp[x][result];
  }
  if (dp[x][result] != -1) {
    return dp[x][result];
  }

  long long int temp = 0;
  temp += func(x + 1, result + arr[x]);
  temp += func(x + 1, result - arr[x]);
  dp[x][result] = temp;
  return dp[x][result];
}

int main() {
  scanf("%d", &n);
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
  }
  printf("%d\n", func(2, arr[1]));
}