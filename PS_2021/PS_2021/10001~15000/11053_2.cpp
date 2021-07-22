#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int N;
int board[MAX], dp[MAX];
vector<int> lis[MAX], answer;

int main() {
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    scanf("%d", &board[i]);
  }
  for (int i = 1; i < N + 1; i++) {
    dp[i] = 1;
    lis[i].push_back(board[i]);
    for (int j = 1; j < i; j++) {
      if (board[j] < board[i]) {
        continue;
      }
    }
    if (answer.size() < lis[i].size()) {
      answer = lis[i];
    }
  }
  for (int i = 0; i < answer.size(); i++) {
    if (i == answer.size() - 1) {
      printf("%d\n", answer[i]);
    } else {
      printf("%d ", answer[i]);
    }
  }
}