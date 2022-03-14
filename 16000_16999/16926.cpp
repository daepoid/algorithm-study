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
int ul, ll, lr, ur;

void rotate() {
  for (int k = 0; 2 * k <= n / 2 && 2 * k <= m / 2; k++) {
    ul = board[k][k];
    ll = board[n - 1 - k][k];
    lr = board[n - 1 - k][m - 1 - k];
    ur = board[k][m - 1 - k];

    for (int i = k; i < n - k - 1; i++) {
      board[k][i] = board[k][i + 1];
    }
    for (int i = n - 1 - k; i > k; i--) {
      board[i][k] = board[i - 1][k];
    }
    for (int i = m - 1 - k; i > k; i--) {
      board[n - 1 - k][i] = board[n - 1 - k][i - 1];
    }
    for (int i = k; i < n - 1 - k; i++) {
      board[i][m - 1 - k] = board[i + 1][m - 1 - k];
    }
    board[k + 1][k] = ul;
    board[n - 1 - k][k + 1] = ll;
    board[n - 2 - k][m - 1 - k] = lr;
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

  scanf("%d %d %d", &n, &m, &r);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = 0; i < r; i++) {
    rotate();
  }
  print_board();
}