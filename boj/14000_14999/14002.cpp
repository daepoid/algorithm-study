#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int N;
int board[MAX], dp[MAX];
vector<int> answer, lis[MAX];

int main() {
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    scanf("%d", &board[i]);
  }

  for (int i = 1; i < N + 1; i++) {
    dp[i] = 1;
    lis[i].push_back(board[i]);
    for (int j = 1; j < i; j++) {
      if (board[i] <= board[j]) {
        continue;
      }
      if (dp[i] > dp[j]) {
        continue;
      }
      lis[i].clear();
      lis[i] = lis[j];
      lis[i].push_back(board[i]);
      dp[i] = dp[j] + 1;
    }
    if (answer.size() < lis[i].size()) {
      answer = lis[i];
    }
  }
  printf("%d\n", answer.size());
  for (int i = 0; i < answer.size(); i++) {
    if (i == answer.size() - 1) {
      printf("%d\n", answer[i]);
    } else {
      printf("%d ", answer[i]);
    }
  }
}