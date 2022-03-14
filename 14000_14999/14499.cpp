#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int n, m, x, y, k;
int board[MAX][MAX];
int dice[7];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

void move_dice(int dir) {
  int temp[7];
  for (int i = 1; i < 7; i++) {
    temp[i] = dice[i];
  }
  if (dir == 1) {
    dice[1] = temp[4];
    dice[4] = temp[6];
    dice[6] = temp[3];
    dice[3] = temp[1];
  } else if (dir == 2) {
    dice[4] = temp[1];
    dice[1] = temp[3];
    dice[3] = temp[6];
    dice[6] = temp[4];
  } else if (dir == 3) {
    dice[2] = temp[1];
    dice[1] = temp[5];
    dice[5] = temp[6];
    dice[6] = temp[2];
  } else if (dir == 4) {
    dice[1] = temp[2];
    dice[5] = temp[1];
    dice[6] = temp[5];
    dice[2] = temp[6];
  }
}

int main() {
  scanf("%d %d %d %d %d", &n, &m, &y, &x, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  int dir;
  for (int i = 0; i < k; i++) {
    scanf("%d", &dir);
    int newy = y + dy[dir - 1];
    int newx = x + dx[dir - 1];
    if (!isvalid(newy, newx)) {
      continue;
    }
    move_dice(dir);
    if (board[newy][newx] == 0) {
      board[newy][newx] = dice[1];
    } else {
      dice[1] = board[newy][newx];
      board[newy][newx] = 0;
    }
    printf("%d\n", dice[6]);
    y = newy;
    x = newx;
  }
}