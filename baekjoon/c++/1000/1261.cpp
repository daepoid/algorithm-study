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
#define MAX 2100000000
using namespace std;

int m, n;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
char board[111][111];
int visited[111][111];

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

void bfs() {
  int x, y;
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  visited[0][0] = 0;

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (!isvalid(newy, newx)) {
        continue;
      }

      if (board[newy][newx] == '1' && visited[newy][newx] > visited[y][x] + 1) {
        visited[newy][newx] = visited[y][x] + 1;
        q.push(make_pair(newy, newx));
      }
      if (board[newy][newx] == '0' && visited[newy][newx] > visited[y][x]) {
        visited[newy][newx] = visited[y][x];
        q.push(make_pair(newy, newx));
      }
    }
  }
}

int main() {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", board[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = MAX;
    }
  }
  bfs();
  printf("%d\n", visited[n - 1][m - 1]);
}