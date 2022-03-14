#include <bits/stdc++.h>
#define MAX 1111
using namespace std;

int N, M, answer = 0;
int board[MAX][MAX];

bool is_square(int a, int b, int size) {
  for (int i = a; i < a + size; i++) {
    for (int j = b; j < b + size; j++) {
      if (board[i][j] == 0) {
        return false;
      }
    }
  }
  return true;
}

bool find_square(int size) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (is_square(i, j, size)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  char s[MAX];
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%s", s);
    for (int j = 0; j < M; j++) {
      board[i][j] = s[j] - '0';
      answer = max(answer, board[i][j]);
    }
  }
  if (answer == 0) {
    printf("0\n");
    return 0;
  }
  int max_square_size = min(N, M);
  for (int size = 2; size <= max_square_size; size++) {
    if (find_square(size)) {
      answer = size;
    } else {
      break;
    }
  }
  printf("%d\n", answer * answer);
}