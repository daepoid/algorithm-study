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

int n, sum = 0, min_sum = 100000000;
int arr[10];
int board[10][10];

void dfs(int cnt) {
  bool flag = false;
  if (cnt == n) {
    min_sum = min(sum + board[arr[n - 1]][arr[0]], min_sum);
    return;
  }
  for (int i = 0; i < n; i++) {
    flag = false;
    for (int j = 0; j < cnt; j++) {
      if (arr[j] == i) {
        flag = true;
        break;
      }
    }
    if (flag) {
      continue;
    }
    sum += board[arr[cnt - 1]][i];
    arr[cnt] = i;
    dfs(cnt + 1);
    sum -= board[arr[cnt - 1]][i];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] == 0) {
        board[i][j] = 100000000;
      }
    }
  }
  dfs(1);
  printf("%d\n", min_sum);
}