#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n, l;

bool isvalid(int board[][MAX], int i, int j) {
  int temp = board[i][j + 1];
  for (int k = j + 1; k < j + 1 + l; k++) {
    if (board[i][k] != temp) {
      return false;
    }
  }
  return true;
}

int sol(int board[][MAX]) {
  int before, total = 0;
  bool flag;
  for (int i = 0; i < n; i++) {
    flag = true;
    before = 1;
    for (int j = 0; j < n - 1; j++) {
      if (board[i][j] == board[i][j + 1]) {
        before++;
      } else if (board[i][j] == board[i][j + 1] + 1) {
        if (isvalid(board, i, j)) {
          j += (l - 1);
          before = 0;
        } else {
          flag = false;
          break;
        }
      } else if (board[i][j] == board[i][j + 1] - 1) {
        if (before >= l) {
          before = 1;
        } else {
          flag = false;
          break;
        }
      } else if (abs(board[i][j] - board[i][j + 1]) > 1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      total++;
    }
  }
  return total;
}

int main() {
  int board[MAX][MAX], board2[MAX][MAX];
  scanf("%d %d", &n, &l);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &board[i][j]);
      board2[j][i] = board[i][j];
    }
  }
  printf("%d\n", sol(board) + sol(board2));
}