#include <bits/stdc++.h>
#define MAX 12
#define CHESS_MAX 10
using namespace std;

struct CHESS {
  int y;
  int x;
  int dir;
};

int board[MAX][MAX];
vector<int> board_state[MAX][MAX];
CHESS chess[CHESS_MAX];

int N, K;
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

int find_position(int y, int x, int idx) {
  for (int i = 0; i < board_state[y][x].size(); i++) {
    if (board_state[y][x][i] == idx) {
      return i;
    }
  }
  return -1;
}

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

int find_del_num(int y, int x, int chess_num) {
  int cnt = 0;
  for (int i = board_state[y][x].size() - 1; i >= 0; i--) {
    if (board_state[y][x][i] == chess_num) {
      break;
    }
    cnt++;
  }
  return cnt + 1;
}

int reverse_dir(int num) {
  switch (chess[num].dir) {
  case 1:
    return 2;
  case 2:
    return 1;
  case 3:
    return 4;
  case 4:
    return 3;
  default:
    return 0;
  }
}

void movechess(int y, int x, int newy, int newx, int chess_num, int pos,
               int s) {
  if (s == 0) {
    for (int i = pos; i < board_state[y][x].size(); i++) {
      board_state[newy][newx].push_back(board_state[y][x][i]);
      int idx = board_state[y][x][i];
      chess[idx].y = newy;
      chess[idx].x = newx;
    }
    int del_num = find_del_num(y, x, chess_num);
    for (int i = 0; i < del_num; i++) {
      board_state[y][x].pop_back();
    }
  } else if (s == 1) {
    for (int i = board_state[y][x].size() - 1; i >= pos; i--) {
      board_state[newy][newx].push_back(board_state[y][x][i]);
      int idx = board_state[y][x][i];
      chess[idx].y = newy;
      chess[idx].x = newx;
    }
    int del_num = find_del_num(y, x, chess_num);
    for (int i = 0; i < del_num; i++) {
      board_state[y][x].pop_back();
    }
  } else if (s == 2) {
    int dir = reverse_dir(chess_num);
    chess[chess_num].dir = dir;
    newy = y + dy[dir];
    newx = x + dx[dir];
    if (isvalid(newy, newx)) {
      if (board[newy][newx] != 2) {
        movechess(y, x, newy, newx, chess_num, pos, board[newy][newx]);
      }
    }
  }
}

bool check_state() {
  for (int i = 0; i < K; i++) {
    int y = chess[i].y;
    int x = chess[i].x;
    if (board_state[y][x].size() >= 4) {
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  for (int i = 0; i < K; i++) {
    int y, x, d;
    scanf("%d %d %d", &y, &x, &d);
    y--;
    x--;
    chess[i] = {y, x, d};
    board_state[y][x].push_back(i);
  }

  int nowtime = 0;
  while (true) {
    if (nowtime > 1000) {
      printf("-1\n");
      return 0;
    }
    for (int i = 0; i < K; i++) {
      int y = chess[i].y;
      int x = chess[i].x;
      int dir = chess[i].dir;
      int newy = y + dy[dir];
      int newx = x + dx[dir];

      int pos = find_position(y, x, i);
      if (isvalid(newy, newx)) {
        movechess(y, x, newy, newx, i, pos, board[newy][newx]);
      } else {
        movechess(y, x, newy, newx, i, pos, 2);
      }
      if (check_state()) {
        printf("%d\n", nowtime + 1);
        return 0;
      }
    }
    nowtime++;
  }
}