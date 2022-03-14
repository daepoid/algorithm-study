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
#define MAX 333
using namespace std;

int board[MAX][MAX];
int n, m, r;

long long int gcd(long long int a, long long int b) {
  long long int temp;

  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}

void rotate() {
  int y1 = 0;
  int x1 = 0;

  int y2 = n - 1;
  int x2 = 0;

  int y3 = n - 1;
  int x3 = m - 1;

  int y4 = 0;
  int x4 = m - 1;

  while ((y1 < y2) && (x1 < x4)) {
    int temp = board[y2][x2];
    for (int i = y2; i > y1; i--) {
      board[i][x2] = board[i - 1][x2];
    }
    for (int j = x1; j < x4; j++) {
      board[y1][j] = board[y1][j + 1];
    }
    for (int i = y4; i < y3; i++) {
      board[i][x4] = board[i + 1][x4];
    }
    for (int j = x3; j > x2; j--) {
      board[y3][j] = board[y3][j - 1];
    }
    board[y2][x2 + 1] = temp;
    y1 += 1;
    x1 += 1;

    y2 -= 1;
    x2 += 1;

    y3 -= 1;
    x3 -= 1;

    y4 += 1;
    x4 -= 1;
  }
}

void print_board() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j == m - 1) {
        printf("%d\n", board[i][j]);
      } else {
        printf("%d ", board[i][j]);
      }
    }
  }
}

int main() {
  long long int temp;
  scanf("%d %d %d", &n, &m, &r);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  temp = 2 * n + 2 * m - 4;
  for (int i = 2; n - i > 0 && m - i > 0; i += 2) {
    temp = lcm(temp, 2 * (n - i) + 2 * (m - i) - 4);
  }
  r %= temp;

  while (r-- > 0) {
    rotate();
  }
  print_board();
}