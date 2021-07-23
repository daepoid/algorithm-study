#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int N, arr[MAX], dp[MAX];
vector<int> lis[MAX], answer;

int main() {
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    scanf("%d", &arr[i]);
  }

  for (int i = 1; i < N + 1; i++) {
    dp[i] = 1;
    lis[i].push_back(arr[i]);
    for (int j = 1; j < i; j++) {
      if (arr[i] <= arr[j]) {
        continue;
      }
      if (dp[i] > dp[j]) {
        continue;
      }
      lis[i].clear();
      lis[i] = lis[j];
      lis[i].push_back(arr[i]);
      dp[i] = dp[j] + 1;
    }
    if (answer.size() < lis[i].size()) {
      answer = lis[i];
    }
  }
  printf("%d\n", answer.size());
}