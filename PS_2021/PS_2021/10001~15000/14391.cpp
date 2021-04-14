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

int main() {
  int n, m, temp, sum_row = 0, sum_col = 0;
  int board[5][5];
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    for (int j = m - 1; j >= 0; j--) {
      board[i][j] = temp % 10;
      temp /= 10;
    }
  }
  for (int i = 0; i < n; i++) {
    temp = 0;
    for (int j = 0; j < m; j++) {
      temp = temp * 10 + board[i][j];
    }
    sum_col += temp;
  }
  for (int i = 0; i < m; i++) {
    temp = 0;
    for (int j = 0; j < n; j++) {
      temp = temp * 10 + board[j][i];
    }
    sum_row += temp;
  }
  printf("%d\n", max(sum_col, sum_row));
}
