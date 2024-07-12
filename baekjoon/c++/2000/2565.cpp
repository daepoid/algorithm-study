#include <bits/stdc++.h>
#define MAX 555
using namespace std;

pair<int, int> v[MAX];
int dp[MAX], answer = 0;

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    v[i].first = a;
    v[i].second = b;
  }

  sort(v + 1, v + N + 1);

  for (int i = 1; i < N + 1; i++) {
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (v[i].second > v[j].second) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    answer = max(answer, dp[i]);
  }
  printf("%d\n", N - answer);
}