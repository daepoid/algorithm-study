#include <bits/stdc++.h>
#define MAX 50 + 1
using namespace std;

struct FIREBALL {
  int m;
  int d;
  int s;
  int age;
};

int N, M, K;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<FIREBALL> board[MAX][MAX];

void move_fireball(int y, int x, int idx) {
  int dir = board[y][x][idx].d;
  int speed = board[y][x][idx].s;
  int newy = y + dy[dir] * (speed % N);
  int newx = x + dx[dir] * (speed % N);

  if (newy > N) {
    newy -= N;
  }
  if (newx > N) {
    newx -= N;
  }
  if (newy < 1) {
    newy += N;
  }
  if (newx < 1) {
    newx += N;
  }
  board[y][x][idx].age++;
  board[newy][newx].push_back(board[y][x][idx]);
  board[y][x].erase(board[y][x].begin() + idx);
}

void sharks_move_order(int age) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (board[i][j].size() < 1) {
        continue;
      }
      for (int k = 0; k < board[i][j].size(); k++) {
        if (board[i][j][k].age == age) {
          move_fireball(i, j, k);
        }
      }
    }
  }
}

void check_fireball_pos() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (board[i][j].size() > 1) {
        int newm = 0;
        int news = 0;
        int cnt_even = 0;
        int size = board[i][j].size();
        int newage = board[i][j][0].age + 1;

        for (int k = 0; k < size; k++) {
          newm += board[i][j][k].m;
          news += board[i][j][k].s;
          if (board[i][j][k].d % 2 == 0) {
            cnt_even++;
          }
        }
        newm /= 5;
        news /= size;
        board[i][j].clear();
        if (newm == 0) {
          continue;
        }
        for (int k = 0; k < 4; k++) {
          if (cnt_even == 0 || cnt_even == size) {
            board[i][j].push_back({newm, k * 2, news, newage});
          } else {
            board[i][j].push_back({newm, k * 2 + 1, news, newage});
          }
        }
      }
    }
  }
}

int sum_fireball() {
  int total = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (board[i][j].size() > 0) {
        for (int k = 0; k < board[i][j].size(); k++) {
          total += board[i][j][k].m;
        }
      }
    }
  }
  return total;
}

int main() {
  scanf("%d %d %d", &N, &M, &K);
  int r, c, m, d, s;
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d %d %d", &r, &c, &m, &d, &s);
    FIREBALL temp = {m, d, s, 0};
    board[r][c].push_back(temp);
  }

  for (int i = 0; i < K; i++) {
    sharks_move_order(i);
    check_fireball_pos();
  }
  printf("%d", sum_fireball());
}