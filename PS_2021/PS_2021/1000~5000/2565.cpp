#include <bits/stdc++.h>
#define MAX 555
using namespace std;

pair<int, int> v[MAX];
int dp[MAX];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    v[i].first = a;
    v[i].second = b;
  }

  int correct = 0;
  sort(v + 1, v + N + 1);
  for (int i = 1; i < N + 1; i++) {
  }
}