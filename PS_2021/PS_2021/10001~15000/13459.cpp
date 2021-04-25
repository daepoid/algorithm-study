#include <bits/stdc++.h>
#define MAX 11
using namespace std;

int N, M, answer = 11;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
char board[MAX][MAX];
string str = "";
pair<int, int> blue, red;

int move_dist(int y, int x, int newy, int newx) {
  return abs(newy - y) + abs(newx - x);
}

void move(int ry, int rx, int by, int bx, int cnt, int dir, string stock) {
  if (cnt >= answer) {
    return;
  }
  if (cnt > 10) {
    return;
  }
  bool red_flag = false;
  bool blue_flag = false;

  int newry = ry + dy[dir];
  int newrx = rx + dx[dir];
  while (true) {
    if (board[newry][newrx] == '#') {
      break;
    }
    if (board[newry][newrx] == 'O') {
      red_flag = true;
      break;
    }
    newry += dy[dir];
    newrx += dx[dir];
  }
  newry -= dy[dir];
  newrx -= dx[dir];

  int newby = by + dy[dir];
  int newbx = bx + dx[dir];
  while (true) {
    if (board[newby][newbx] == '#') {
      break;
    }
    if (board[newby][newbx] == 'O') {
      blue_flag = true;
      break;
    }
    newby += dy[dir];
    newbx += dx[dir];
  }
  newby -= dy[dir];
  newbx -= dx[dir];

  if (blue_flag) {
    return;
  } else if (red_flag) {
    answer = min(answer, cnt);
    str = stock;
    return;
  }

  if (newry == newby && newrx == newbx) {
    int red_dist = move_dist(ry, rx, newry, newrx);
    int blue_dist = move_dist(by, bx, newby, newbx);
    if (red_dist > blue_dist) {
      newry -= dy[dir];
      newrx -= dx[dir];
    } else {
      newby -= dy[dir];
      newbx -= dx[dir];
    }
  }

  for (int i = 0; i < 4; i++) {
    if (i % 2 == dir % 2) {
      continue;
    }
    move(newry, newrx, newby, newbx, cnt + 1, i, stock + to_string(i));
  }
}

int main() {
  char C;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf(" %c", &C);
      board[i][j] = C;
      if (C == 'B') {
        blue = {i, j};
        board[i][j] = '.';
      }
      if (C == 'R') {
        red = {i, j};
        board[i][j] = '.';
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    int ry = red.first;
    int rx = red.second;
    int by = blue.first;
    int bx = blue.second;
    string stock = "";

    move(ry, rx, by, bx, 1, i, stock + to_string(i));
  }
  if (answer > 10) {
    printf("-1\n");
    return 0;
  } else {
    printf("%d\n", answer);
    for (int i = 0; i < str.length(); i++) {
      char temp;
      switch (str[i]) {
      case '0':
        printf("R");
        break;
      case '1':
        printf("U");
        break;
      case '2':
        printf("L");
      case '3':
        printf("D");
        break;
      default:
        printf("E");
        break;
      }
    }
    printf("\n");
  }
}