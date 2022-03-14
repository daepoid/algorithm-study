#include <bits/stdc++.h>
#define MAX 1111
using namespace std;

int N, M;
int dp[MAX][MAX];
char board[MAX][MAX];

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

bool is_square(int a, int b, int size) {
  for (int i = a; i < a + size; i++) {
    for (int j = b; j < b + size; j++) {
      if (board[i][j] == '0') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int answer = 0;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%s", board[i]);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == '0') {
        continue;
      }
      while (true) {
        if (!isvalid(i + answer, j + answer)) {
          break;
        }
        if (!is_square(i, j, answer + 1)) {
          break;
        }
        answer++;
      }
    }
  }
  printf("%d\n", answer * answer);
}