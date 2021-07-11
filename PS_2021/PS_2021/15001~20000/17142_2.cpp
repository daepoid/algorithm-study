#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int board[MAX][MAX], N, M;
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
bool before[MAX][MAX];
vector<pair<int, int>> moves, clouds;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

void move_cloud(int dir, int len) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      before[i][j] = false;
    }
  }

  for (int i = 0; i < clouds.size(); i++) {
    int y = clouds[i].first;
    int x = clouds[i].second;

    y += (dy[dir] * len);
    while (y < 0) {
      y += N;
    }
    while (y >= N) {
      y -= N;
    }

    x += (dx[dir] * len);
    while (x < 0) {
      x += N;
    }
    while (x >= N) {
      x -= N;
    }
    clouds[i].first = y;
    clouds[i].second = x;
    before[y][x] = true;
  }
}

void rain() {
  for (int i = 0; i < clouds.size(); i++) {
    board[clouds[i].first][clouds[i].second]++;
  }
}

void clear_cloud() { clouds.clear(); }

void water_copy_magic() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (before[i][j]) {
        for (int a = 1; a < 8; a += 2) {
          int newy = i + dy[a];
          int newx = j + dx[a];
          if (isvalid(newy, newx) && board[newy][newx] > 0) {
            board[i][j]++;
          }
        }
      }
    }
  }
}

void make_cloud() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] >= 2 && !before[i][j]) {
        clouds.push_back({i, j});
        before[i][j] = true;
        board[i][j] -= 2;
      } else {
        before[i][j] = false;
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  clouds.push_back({N - 1, 0});
  clouds.push_back({N - 1, 1});
  clouds.push_back({N - 2, 0});
  clouds.push_back({N - 2, 1});

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  int a, b;
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &a, &b);
    moves.push_back({a - 1, b});
  }

  for (int i = 0; i < M; i++) {
    move_cloud(moves[i].first, moves[i].second);
    rain();
    clear_cloud();
    water_copy_magic();
    make_cloud();
  }
  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sum += board[i][j];
    }
  }
  printf("%d\n", sum);
}