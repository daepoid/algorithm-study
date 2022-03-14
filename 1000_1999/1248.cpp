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

int n;
char board[10][10];
int arr[11];

bool check_board(int index) {
  int sum = 0;
  for (int i = index; i >= 0; i--) {
    sum += arr[i];
    if (board[i][index] == '+' && sum <= 0) {
      return false;
    } else if (board[i][index] == '-' && sum >= 0) {
      return false;
    } else if (board[i][index] == '0' && sum != 0) {
      return false;
    }
  }
  return true;
}

void dfs(int cnt) {
  if (cnt == n) {
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        printf("%d\n", arr[i]);
      } else {
        printf("%d ", arr[i]);
      }
    }
    exit(0);
  }
  for (int i = -10; i <= 10; i++) {
    arr[cnt] = i;
    if (check_board(cnt)) {
      dfs(cnt + 1);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      cin >> board[i][j];
    }
  }
  dfs(0);
}