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

char board[51][51];

int cnt_seq(int i, int j, int n) {
  int cnt = 1, ans = 0;
  for (int k = 0; k < 2; k++) {
    cnt = 1;
    for (int l = 1; l < n; l++) {
      if (board[l - 1][j + k] == board[l][j + k]) {
        cnt++;
      } else {
        ans = max(ans, cnt);
        cnt = 1;
      }
    }
    ans = max(ans, cnt);
  }
  cnt = 0;
  for (int k = 0; k < 2; k++) {
    cnt = 1;
    for (int l = 1; l < n; l++) {
      if (board[j + k][l - 1] == board[j + k][l]) {
        cnt++;
      } else {
        ans = max(ans, cnt);
        cnt = 1;
      }
    }
  }
  ans = max(ans, cnt);
  return ans;
}

int main() {
  int n, ans = 0, cnt = 0, cnt2 = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", board[i]);
  }
  for (int i = 0; i < n; i++) {
    cnt = 1;
    cnt2 = 1;
    for (int j = 1; j < n; j++) {
      if (board[i][j - 1] == board[i][j]) {
        cnt++;
      } else {
        ans = max(ans, cnt);
        cnt = 1;
      }
      if (board[j - 1][i] == board[j][i]) {
        cnt2++;
      } else {
        ans = max(ans, cnt2);
        cnt2 = 1;
      }
    }
    ans = max(ans, cnt);
    ans = max(ans, cnt2);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      swap(board[i][j], board[i][j + 1]);
      ans = max(ans, cnt_seq(i, j, n));
      swap(board[i][j], board[i][j + 1]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      swap(board[j][i], board[j + 1][i]);
      ans = max(ans, cnt_seq(i, j, n));
      swap(board[j][i], board[j + 1][i]);
    }
  }
  printf("%d\n", ans);
}