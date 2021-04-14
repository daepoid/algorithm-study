#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int board[9][9];

void print_sudoku() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (j == 8) {
        printf("%d\n", board[i][j]);
      } else {
        printf("%d ", board[i][j]);
      }
    }
  }
}

void solve(int i, int j) {}

int main() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == 0) {
        solve(i, j);
      }
    }
  }
  print_sudoku();
}