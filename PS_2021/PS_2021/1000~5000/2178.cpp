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

int n, m;
char board[101][101];
int cnt[101][101];
bool visited[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool is_valid(int num, int a, int b) { return a <= num && num < b; }

bool chk_board(int a, int b) {
  return board[b][a] == '1' && !visited[b][a] && cnt[b][a] == 0;
}

void bfs(int i, int j) {
  visited[i][j] = true;
  queue<pair<int, int>> q;
  q.push(make_pair(i, j));
  while (!q.empty()) {
    int x = q.front().second;
    int y = q.front().first;
    q.pop();
    for (int k = 0; k < 4; k++) {
      int newx = x + dx[k];
      int newy = y + dy[k];
      if (is_valid(newx, 0, m) && is_valid(newy, 0, m) &&
          chk_board(newx, newy)) {
        cnt[newy][newx] = cnt[y][x] + 1;
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
  printf("%d\n", cnt[n - 1][n - 1] + 1);
}