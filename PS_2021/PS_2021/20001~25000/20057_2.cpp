#include <bits/stdc++.h>
#define MAX 499 + 2 * 2
using namespace std;

int N, board[MAX][MAX], answer = 0;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int ydy[4][10] = {{-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
                  {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
                  {0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
                  {0, 0, -1, -1, -2, -2, -1, -1, -3, -2}};
int xdx[4][10] = {{0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
                  {0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
                  {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
                  {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}};
int percent[9] = {1, 1, 7, 7, 10, 10, 2, 2, 5};

bool isvalid(int newy, int newx) {
  return 0 < newy && newy <= N && 0 < newx && newx <= N;
}

void spread_sand(int y, int x, int dir) {
  int tornado_y = y + dy[dir];
  int tornado_x = x + dx[dir];
  if (board[tornado_y][tornado_x] == 0) {
    return;
  }

  int sand = board[tornado_y][tornado_x];
  int temp = sand;
  for (int i = 0; i < 9; i++) {
    int newy = y + ydy[dir][i];
    int newx = x + xdx[dir][i];
    int per = percent[i];
    int plus = temp * per / 100;

    if (!isvalid(newy, newx)) {
      answer += plus;
    } else {
      board[newy][newx] += plus;
    }
    sand -= plus;
  }
  int newy = y + ydy[dir][9];
  int newx = x + xdx[dir][9];
  if (!isvalid(newy, newx)) {
    answer += sand;
  } else {
    board[newy][newx] += sand;
  }
  board[tornado_y][tornado_x] = 0;
}

int change_dir(int dir) {
  if (dir == 0) {
    return 3;
  }
  if (dir == 1) {
    return 2;
  }
  if (dir == 2) {
    return 0;
  }
  if (dir == 3) {
    return 1;
  }
  return -1;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  int y = (N + 1) / 2;
  int x = (N + 1) / 2;
  int dir = 1;
  int move_cnt = 1;

  while (true) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < move_cnt; j++) {
        spread_sand(y, x, dir);
        y += dy[dir];
        x += dx[dir];
      }
      dir = change_dir(dir);
    }
    move_cnt++;
    if (move_cnt == N) {
      for (int j = 0; j < move_cnt; j++) {
        spread_sand(y, x, dir);
        y += dy[dir];
        x += dx[dir];
      }
      break;
    }
  }
  printf("%d\n", answer);
}