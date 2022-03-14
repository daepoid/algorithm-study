#include <bits/stdc++.h>
#define MAX 55
using namespace std;

int N, M, board[MAX][MAX], dir_board[MAX][MAX];
int max_size;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int ddy[4] = {0, 1, 0, -1};
int ddx[4] = {-1, 0, 1, 0};
bool bomb_flag = true;
int bomb_arr[4];
vector<pair<int, int>> emptyv, marble_arr;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

void build_LUT() {
  int y = N / 2;
  int x = N / 2;
  int dir = 0;
  int move_cnt = 1;
  while (true) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < move_cnt; j++) {
        dir_board[y][x] = dir;
        y += ddy[dir];
        x += ddx[dir];
      }
      dir = (dir + 1) % 4;
    }
    move_cnt++;
    if (move_cnt == N) {
      for (int j = 0; j < move_cnt; j++) {
        dir_board[y][x] = dir;
        y += ddy[dir];
        x += ddx[dir];
      }
      break;
    }
  }
}

void blizard(int dir, int len) {
  int newy = N / 2;
  int newx = N / 2;
  for (int i = 0; i < len; i++) {
    newy += dy[dir];
    newx += dx[dir];
    if (!isvalid(newy, newx)) {
      continue;
    }
    if (board[newy][newx] != 0) {
      emptyv.push_back({newy, newx});
      board[newy][newx] = 0;
    }
  }
}

void fillin() {
  for (int i = emptyv.size() - 1; i >= 0; i--) {
    int y = emptyv[i].first;
    int x = emptyv[i].second;
    while (true) {
      int dir = dir_board[y][x];
      int newy = y + ddy[dir];
      int newx = x + ddx[dir];
      if (board[newy][newx] == 0) {
        board[y][x] = board[newy][newx];
        break;
      }
      board[y][x] = board[newy][newx];
      y = newy;
      x = newx;
    }
  }
  emptyv.clear();
}

void make_marble_arr() {
  marble_arr.clear();
  int y = N / 2;
  int x = N / 2;
  int dir = 0;
  int move_cnt = 1;
  int before = 0;
  int cnt = 1;
  while (true) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < move_cnt; j++) {
        y += ddy[dir];
        x += ddx[dir];
        if (board[y][x] == before) {
          cnt++;
        } else {
          marble_arr.push_back({cnt, before});
          before = board[y][x];
          cnt = 1;
        }
      }
      dir = (dir + 1) % 4;
    }
    move_cnt++;
    if (move_cnt == N) {
      for (int j = 0; j < move_cnt; j++) {
        y += ddy[dir];
        x += ddx[dir];
        if (board[y][x] == before) {
          cnt++;
        } else {
          marble_arr.push_back({cnt, before});
          before = board[y][x];
          cnt = 1;
        }
      }
      break;
    }
  }
  marble_arr.erase(marble_arr.begin());
}

void bomb() {
  int size = max_size;
  if (marble_arr.size() > max_size) {
    marble_arr.erase(marble_arr.begin() + max_size + 1, marble_arr.end());
  }

  for (int i = 0; i < size; i++) {
    if (marble_arr[i].first >= 4) {
      bomb_arr[marble_arr[i].first] += marble_arr[i].second;
      marble_arr.erase(marble_arr.begin() + i);
      i--;
      size--;
      bomb_flag = true;
    }
  }
}

void fillin_board() {
  memset(board, 0, sizeof(board));
  int y = N / 2;
  int x = N / 2;
  int dir = 0;
  int move_cnt = 1;
  bool flag = true;
  int cnt = 0;
  while (true) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < move_cnt; j++) {
        y += ddy[dir];
        x += ddx[dir];
        if (true) {
          board[y][x] = marble_arr[cnt].first;
        } else {
          board[y][x] = marble_arr[cnt].second;
        }
      }
      dir = (dir + 1) % 4;
    }
    move_cnt++;
    if (move_cnt == N) {
      for (int j = 0; j < move_cnt; j++) {
        y += ddy[dir];
        x += ddx[dir];
        if (true) {
          board[y][x] = marble_arr[cnt].first;
        } else {
          board[y][x] = marble_arr[cnt].second;
        }
      }
      break;
    }
  }
}

void change_marble() {}

int main() {
  int d, s;
  scanf("%d %d", &N, &M);
  max_size = (N * N - 1) / 2;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  build_LUT();
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &d, &s);
    blizard(d - 1, s);
    fillin();
    bomb_flag = true;
    while (bomb_flag) {
      bomb_flag = false;
      make_marble_arr();
      bomb();
      fillin_board();
    }
    change_marble();
  }
  printf("%d\n", bomb_arr[1] + bomb_arr[2] * 2 + bomb_arr[3] * 3);
}