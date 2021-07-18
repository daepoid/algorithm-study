#include <bits/stdc++.h>
#define MAX 111
#define C_MAX 100011
using namespace std;

int N, K;
int C[MAX];
int dp[C_MAX];

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%d", &C[i]);
  }

  sort(C, C + N, greater<int>());

  for (int i = 1; i < K + 1; i++) {
    for (int j = 0; j < N; j++) {
        
    }
  }

  for (int i = 0; i < N; i++) {
    int val = C[i];
    if (K < val) {
      continue;
    }
  }
}