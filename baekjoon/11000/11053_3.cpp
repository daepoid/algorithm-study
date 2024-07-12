#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int N, temp, answer;
int arr[MAX], dp[MAX];

int main() {
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    scanf("%d", &arr[i]);
  }

  for (int j = 1; j < N + 1; j++) {
    temp = 0;
    for (int i = 0; i < j; i++) {
      if (arr[j] <= arr[i]) {
        continue;
      }
      if (temp <= dp[i]) {
        continue;
      }
      temp = dp[i];
    }
    dp[j] = temp + 1;
    if (answer < dp[j]) {
      answer = dp[j];
    }
  }
  printf("%d\n", answer);
  return 0;
}