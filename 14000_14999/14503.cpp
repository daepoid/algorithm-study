#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int n, m, r, c, d;
int board[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

int main() {
  scanf("%d %d", &n, &m);
  scanf("%d %d %d", &r, &c, &d);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  int y = r;
  int x = c;
  int dir = d;
  int answer = 1;
  board[y][x] = 2;

  while (true) {
    int temp_dir = dir;
    bool can_clean = false;
    int can_not_clean_count = 0;

    int newdir, newy, newx;
    for (int i = 0; i < 4; i++) {
      newdir = (dir + 3) % 4;
      newy = y + dy[newdir];
      newx = x + dx[newdir];

      if (board[newy][newx] == 0) {
        board[newy][newx] = 2;
        answer++;
        dir = newdir;
        break;
      } else if (board[newy][newx] != 0 || !isvalid(newy, newx)) {
        dir = newdir;
        can_not_clean_count++;
      }
    }
    if (can_not_clean_count == 4) {
      newy = y - dy[temp_dir];
      newx = x - dx[temp_dir];
      dir = temp_dir;
      if (!isvalid(newy, newx) || board[newy][newx] == 1) {
        break;
      }
    }
    y = newy;
    x = newx;
  }
  printf("%d\n", answer);
}