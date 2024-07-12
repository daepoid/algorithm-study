#include <bits/stdc++.h>
#define MAX 101
using namespace std;

char board[2][MAX][MAX];
bool visited[2][MAX][MAX];
int answer[2] = {0, 0}, n;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < n;
}

void bfs(int mod, int y, int x) {
  queue<pair<int, int>> q;
  q.push(make_pair(y, x));
  char color = board[mod][y][x];
  visited[mod][y][x] = true;
  answer[mod]++;

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      } else if (color != board[mod][newy][newx]) {
        continue;
      } else if (visited[mod][newy][newx]) {
        continue;
      }
      visited[mod][newy][newx] = true;
      q.push(make_pair(newy, newx));
    }
  }
}

int main() {
  scanf("%d", &n);
  memset(visited, false, sizeof(visited));

  for (int i = 0; i < n; i++) {
    scanf("%s", board[0][i]);
    for (int j = 0; j < n; j++) {
      if (board[0][i][j] == 'G') {
        board[1][i][j] = 'R';
      } else {
        board[1][i][j] = board[0][i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[0][i][j]) {
        bfs(0, i, j);
      }
      if (!visited[1][i][j]) {
        bfs(1, i, j);
      }
    }
  }
  printf("%d %d\n", answer[0], answer[1]);
}