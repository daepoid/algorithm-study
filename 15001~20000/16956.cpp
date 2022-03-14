#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int R, C;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
char board[MAX][MAX];
bool flag = false;
bool visited[MAX][MAX];
vector<pair<int, int>> v;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < R && 0 <= newx && newx < C;
}

bool bfs(int a, int b) {
  queue<pair<int, int>> q;
  q.push({a, b});
  visited[a][b] = true;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    if (board[y][x] == 'S') {
      return true;
    }

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      }
      if (board[newy][newx] == 'D') {
        continue;
      }
      if (board[newy][newx] == 'W') {
        continue;
      }
      if (visited[newy][newx]) {
        continue;
      }
      visited[newy][newx] = true;
      q.push({newy, newx});
    }
  }
  return false;
}

int main() {
  scanf("%d %d", &R, &C);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf(" %c", &board[i][j]);
      if (board[i][j] == 'W') {
        v.push_back({i, j});
      } else if (board[i][j] == '.') {
        board[i][j] = 'D';
      }
    }
  }

  for (int i = 0; i < v.size(); i++) {
    flag = bfs(v[i].first, v[i].second);
    if (flag) {
      printf("0\n");
      return 0;
    }
  }
  printf("1\n");
  for (int i = 0; i < R; i++) {
    board[i][C] = '\0';
    printf("%s\n", board[i]);
  }
  return 0;
}