#include <bits/stdc++.h>
#define MAX 500
using namespace std;

int N, board[MAX][MAX];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int weight[5][5] = {{0, 0, 2, 0, 0},
                    {0, 10, 7, 1, 0},
                    {5, 0, 0, 0, 0},
                    {0, 10, 7, 1, 0},
                    {0, 0, 2, 0, 0}};
pair<int, int> now_pos;

void move_tornado(int dir) {
  int y = now_pos.first;
  int x = now_pos.second;
  int newy = y + dy[dir];
  int newx = x + dx[dir];
}

void rotate_weight(int dir) {}

void move() {
  int dir = 0;
  bool flag = false;
  for (int len = 0; len < N;) {
    dir = len % 4;
    for (int j = 0; j <= len; j++) {
      move_tornado(dir);
    }
    if (!flag) {
      flag = true;
    } else if (flag) {
      flag = false;
      rotate_weight(dir);
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  move();
}