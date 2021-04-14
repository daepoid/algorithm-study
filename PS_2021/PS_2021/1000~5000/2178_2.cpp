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

int ans, n, m;
char board[111][111], visited[111][111];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int dp[111][111];

bool isvalid(int i, int j) { return 0 <= i && i < n && 0 <= j && j < m; }

void bfs(int i, int j) {
  queue<pair<int, int>> q;
  q.push(make_pair(i, j));
  visited[i][j] = true;

  while (!q.empty()) {
    i = q.front().first;
    j = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++) {
      int newy = dy[k] + i;
      int newx = dx[k] + j;
      if (isvalid(newy, newx) && !visited[newy][newx] &&
          board[newy][newx] == '1' && dp[newy][newx] == 0) {
        dp[newy][newx] = dp[i][j] + 1;
        visited[newy][newx] = true;
        q.push(make_pair(newy, newx));
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", board[i]);
  }
  bfs(0, 0);
  printf("%d\n", dp[n - 1][m - 1] + 1);
}