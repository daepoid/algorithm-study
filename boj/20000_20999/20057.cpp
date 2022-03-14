#include <bits/stdc++.h>
#define MAX 499 + 2 * 2
using namespace std;

int N, board[MAX][MAX], answer = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int weight[5][5] = {{0, 0, 2, 0, 0},
                    {0, 10, 7, 1, 0},
                    {5, 0, 0, 0, 0},
                    {0, 10, 7, 1, 0},
                    {0, 0, 2, 0, 0}};

pair<int, int> pos[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

void rotate_weight() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < i; j++) {
      swap(weight[i][j], weight[j][i]);
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      swap(weight[i][j], weight[4 - i][j]);
    }
  }
}

void move_tornado(int y, int x, int dir) {
  int yy = y + dy[dir];
  int xx = x + dx[dir];
  if (board[yy][xx] == 0) {
    return;
  }

  int now_sand = board[yy][xx];
  int temp = now_sand;

  for (int i = -2; i <= 2; i++) {
    for (int j = -2; j <= 2; j++) {
      int newy = yy + i;
      int newx = xx + j;
      int plus = temp * weight[i + 2][j + 2] / 100;
      if (!isvalid(newy, newx)) {
        answer += plus;
      } else {
        board[newy][newx] += plus;
      }
      now_sand -= plus;
    }
  }
  int newy = yy + pos[dir].first;
  int newx = xx + pos[dir].second;
  if (!isvalid(newy, newx)) {
    answer += now_sand;
  } else {
    board[newy][newx] += now_sand;
  }
  board[yy][xx] = 0;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  int y = N / 2;
  int x = N / 2;
  int dir = 0;
  int move_cnt = 1;
  while (true) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < move_cnt; j++) {
        move_tornado(y, x, dir);
        y += dy[dir];
        x += dx[dir];
      }
      dir = (dir + 1) % 4;
      rotate_weight();
    }
    move_cnt++;
    if (move_cnt == N) {
      for (int j = 0; j < move_cnt; j++) {
        move_tornado(y, x, dir);
        y += dy[dir];
        x += dx[dir];
      }
      break;
    }
  }
  printf("%d\n", answer);
}