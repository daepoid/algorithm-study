#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int N, M;
int board[MAX][MAX];
int dir_board[MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int ddy[4] = {0, 1, 0, -1};
int ddx[4] = {-1, 0, 1, 0};
bool bomb_flag = true;
int bomb_arr[4];
pair<int, int> shark;
vector<pair<int, int>> emptyv;

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
  int y = N / 2;
  int x = N / 2;
  for (int i = 1; i <= len; i++) {
    int newy = y + dy[dir] * i;
    int newx = x + dx[dir] * i;
    if (!isvalid(newy, newx)) {
      continue;
    }
    if (board[newy][newx] != 0) {
      emptyv.push_back({newy, newx});
      board[newy][newx] = 0;
    }
  }
}

void fillin(int a, int b) {
  int y = a;
  int x = b;
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

void bomb() {
  int y = N / 2;
  int x = N / 2;
  int dir = 0;
  int move_cnt = 1;
  int cnt = 1;
  int before = -1;
  bomb_flag = false;
  queue<pair<int, int>> q;
  while (true) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < move_cnt; j++) {
        if (!isvalid(y, x)) {
          y += ddy[dir];
          x += ddx[dir];
          continue;
        }
        if (board[y][x] == 0) {
        } else if (board[y][x] == before) {
          q.push({y, x});
          cnt++;
        } else {
          if (cnt >= 4) {
            while (!q.empty()) {
              int yy = q.front().first;
              int xx = q.front().second;
              q.pop();
              bomb_arr[board[yy][xx]]++;
              board[yy][xx] = 0;
              emptyv.push_back({yy, xx});
            }
            bomb_flag = true;
          }
          before = board[y][x];
          cnt = 1;
          while (!q.empty()) {
            q.pop();
          }
          q.push({y, x});
        }
        y += ddy[dir];
        x += ddx[dir];
      }
      dir = (dir + 1) % 4;
    }
    move_cnt++;
    if (move_cnt == N) {
      for (int j = 0; j < move_cnt; j++) {
        if (board[y][x] == before) {
          q.push({y, x});
          cnt++;
        } else {
          if (cnt >= 4) {
            while (!q.empty()) {
              int yy = q.front().first;
              int xx = q.front().second;
              q.pop();
              bomb_arr[board[yy][xx]]++;
              board[yy][xx] = 0;
              emptyv.push_back({yy, xx});
            }
            bomb_flag = true;
          }
          before = board[y][x];
          cnt = 1;
          while (!q.empty()) {
            q.pop();
          }
          q.push({y, x});
        }
        y += ddy[dir];
        x += ddx[dir];
      }
      break;
    }
  }
}

void change_marble() {
  int newboard[MAX][MAX];
  int y = N / 2;
  int x = N / 2;
  int dir = 0;
  int move_cnt = 1;
  int cnt = 1;
  int before = -1;
  queue<pair<int, int>> q;
  vector<pair<int, int>> v;
  while (true) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < move_cnt; j++) {
        if (before == board[y][x]) {
          cnt++;
        } else {
          v.push_back({cnt, before});
          before = board[y][x];
          cnt = 1;
        }
        y += ddy[dir];
        x += ddx[dir];
      }
      dir = (dir + 1) % 4;
    }
    move_cnt++;
    if (move_cnt == N) {
      for (int j = 0; j < move_cnt; j++) {
        if (j == move_cnt - 1 && before == board[y][x]) {
          cnt++;
          v.push_back({cnt, before});
        }
        if (before == board[y][x]) {
          cnt++;
        } else {
          v.push_back({cnt, before});
          before = board[y][x];
          cnt = 1;
        }
        y += ddy[dir];
        x += ddx[dir];
      }
      break;
    }
  }

  y = N / 2;
  x = N / 2;
  dir = 0;
  move_cnt = 1;
  cnt = 2;
  bool check = true;
  bool end_flag = false;
  while (!end_flag) {
    for (int i = 0; i < 2 && !end_flag; i++) {
      for (int j = 0; j < move_cnt && !end_flag; j++) {
        y += ddy[dir];
        x += ddx[dir];
        if (!isvalid(y, x)) {
          end_flag = true;
          break;
        }
        if (check) {
          check = false;
          if (cnt < v.size()) {
            board[y][x] = v[cnt].first;
          } else {
            board[y][x] = 0;
          }
        } else {
          check = true;
          if (cnt < v.size()) {
            board[y][x] = v[cnt].second;
            cnt++;
          } else {
            board[y][x] = 0;
          }
        }
      }
      dir = (dir + 1) % 4;
    }
    move_cnt++;
  }
}

int main() {
  int d, s;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  build_LUT();
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &d, &s);
    blizard(d - 1, s);
    for (int j = emptyv.size() - 1; j >= 0; j--) {
      fillin(emptyv[j].first, emptyv[j].second);
    }
    emptyv.clear();
    bomb_flag = true;
    while (bomb_flag) {
      bomb();
      for (int j = emptyv.size() - 1; j >= 0; j--) {
        fillin(emptyv[j].first, emptyv[j].second);
      }
      emptyv.clear();
    }
    change_marble();
  }
  printf("%d\n", bomb_arr[1] + bomb_arr[2] * 2 + bomb_arr[3] * 3);
}