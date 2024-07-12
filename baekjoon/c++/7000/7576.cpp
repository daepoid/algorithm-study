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

int m, n, ans = 0;
int board[1001][1001];
int dp[1001][1001];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

void bfs() {
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (isvalid(newy, newx) && board[newy][newx] == 0) {
        board[newy][newx] = board[y][x] + 1;
        q.push(make_pair(newy, newx));
      }
    }
  }
}

int main() {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] == 1) {
        q.push(make_pair(i, j));
      }
    }
  }
  bfs();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 0) {
        printf("-1\n");
        return 0;
      }
      ans = max(ans, board[i][j]);
    }
  }
  printf("%d\n", ans - 1);
}