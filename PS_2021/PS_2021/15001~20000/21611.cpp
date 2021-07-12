#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int N, M;
int board[MAX][MAX];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int sum[3];

void blizard(int d, int s) {
  int ndy[5] = {0, -1, 1, 0, 0};
  int ndx[5] = {0, 0, 0, -1, 1};
  int y = N / 2;
  int x = N / 2;
  for (int i = 0; i < s; i++) {
    y += ndy[d];
    x += ndx[d];
    board[y][x] = 0;
  }
}

void move_marbles() {
  vector<int> temp_list;
  int dir = 0;
  int y = N / 2;
  int x = N / 2;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < i; k++) {
        y += dy[dir];
        x += dx[dir];
        if (board[y][x] != 0) {
          temp_list.push_back(board[y][x]);
        }
        board[y][x] = 0;
      }
      dir = (dir + 1) % 4;
    }
  }

  y = N / 2;
  x = N / 2;
  dir = 0;
  int idx = 0;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < i; k++) {
        y += dy[dir];
        x += dx[dir];
        if (temp_list.size() <= idx) {
          return;
        }
        board[y][x] = temp_list[idx++];
      }
      dir = (dir + 1) % 4;
    }
  }
}

bool is_boomable() {
  vector<int> temp_list;
  int dir = 0;
  int y = N / 2;
  int x = N / 2;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < i; k++) {
        y += dy[dir];
        x += dx[dir];
        if (board[y][x] != 0) {
          temp_list.push_back(board[y][x]);
        }
      }
      dir = (dir + 1) % 4;
    }
  }

  int cnt = 1;
  for (int i = 0; i < temp_list.size(); i++) {
    if (temp_list[i] = temp_list[i + 1]) {
      cnt++;
    } else {
      cnt = 1;
    }
    if (cnt == 4) {
      return true;
    }
  }
  return false;
}

void boom_marbles() {
  vector<int> temp_list;
  int dir = 0;
  int y = N / 2;
  int x = N / 2;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < i; k++) {
        y += dy[dir];
        x += dx[dir];
        if (board[y][x] != 0) {
          temp_list.push_back(board[y][x]);
        }
        board[y][x] = 0;
      }
      dir = (dir + 1) % 4;
    }
  }

  int cnt = 1;
  int idx = 0;
  for (int i = 0; i < temp_list.size(); i++) {
    if (temp_list[i] == temp_list[i + 1]) {
      cnt++;
    }
    if (temp_list[i] != temp_list[i + 1]) {
      if (cnt >= 4) {
        while (cnt > 0) {
          temp_list.erase(temp_list.begin() + idx);
          cnt--;
        }
      }
      idx = i + 1;
      cnt = 1;
    }
  }

  y = N / 2;
  x = N / 2;
  dir = 0;
  idx = 0;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < i; k++) {
        y += dy[dir];
        x += dx[dir];
        if (temp_list.size() <= idx) {
          return;
        }
        board[y][x] = temp_list[idx++];
      }
      dir = (dir + 1) % 4;
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  int d, s;
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &d, &s);
    blizard(d, s);
    move_marbles();
    while (is_boomable()) {
      boom_marbles();
      move_marbles();
    }
  }
  printf("%d\n", sum[0] + sum[1] * 2 + sum[2] * 3);
}