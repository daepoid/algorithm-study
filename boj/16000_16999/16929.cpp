#include <bits/stdc++.h>
using namespace std;

char board[55][55];
bool complete = false;
bool isvisited[55][55];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int n, m;

struct dots {
  int y;
  int x;
  char color;
};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

void dfs(dots origin, dots dot, int cnt) {
  if (cnt > 3 && origin.y == dot.y && origin.x == dot.x &&
      origin.color == dot.color) {
    printf("Yes\n");
    exit(0);
  }
  for (int i = 0; i < 4; i++) {
    int newy = dot.y + dy[i];
    int newx = dot.x + dx[i];
    if (isvalid(newy, newx) && !isvisited[newy][newx] &&
        board[newy][newx] == dot.color) {
      isvisited[newy][newx] = true;
      dfs(origin, {newy, newx, dot.color}, cnt + 1);
      isvisited[newy][newx] = false;
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", board[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!isvisited[i][j]) {
        dfs({i, j, board[i][j]}, {i, j, board[i][j]}, 0);
      }
    }
  }
  printf("No\n");
  return 0;
}