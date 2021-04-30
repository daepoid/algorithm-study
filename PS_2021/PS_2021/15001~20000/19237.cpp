#include <bits/stdc++.h>
#define MAX 20
using namespace std;

struct State {
  vector<int> v;
  pair<int, int> smell;
};

struct FISH {
  int dir;
  pair<int, int> pos;
  int weight[5][4];
  bool live;
};

State board[MAX][MAX];
FISH sharks[MAX * MAX + 1];
int N, M, K, answer = 0;
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};

bool check_sharks() {
  for (int i = 2; i <= M; i++) {
    if (sharks[i].live) {
      return false;
    }
  }
  return true;
}

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

void spread_smell(int time) {
  for (int i = 1; i <= M; i++) {
    if (!sharks[i].live) {
      continue;
    }
    int y = sharks[i].pos.first;
    int x = sharks[i].pos.second;
    board[y][x].smell = {i, time + K};
  }
}

void move_sharks(int time) {
  for (int i = 1; i <= M; i++) {
    if (!sharks[i].live) {
      continue;
    }
    int y = sharks[i].pos.first;
    int x = sharks[i].pos.second;
    board[y][x].v.clear();
  }

  for (int i = 1; i <= M; i++) {
    if (!sharks[i].live) {
      continue;
    }
    int y = sharks[i].pos.first;
    int x = sharks[i].pos.second;
    int dir = sharks[i].dir;
    bool flag = false;
    int my_y = -1;
    int my_x = -1;
    int my_dir = -1;

    for (int j = 0; j < 4; j++) {
      int newdir = sharks[i].weight[dir][j];
      int newy = y + dy[newdir];
      int newx = x + dx[newdir];

      if (isvalid(newy, newx)) {
        if (board[newy][newx].smell.second <= time) {
          flag = true;
          board[newy][newx].v.push_back(i);
          sharks[i].pos = {newy, newx};
          sharks[i].dir = newdir;
          break;
        } else {
          if (board[newy][newx].smell.first == i && my_y == -1) {
            my_y = newy;
            my_x = newx;
            my_dir = newdir;
          }
        }
      }
    }
    if (!flag) {
      board[my_y][my_x].v.push_back(i);
      sharks[i].pos = {my_y, my_x};
      sharks[i].dir = my_dir;
    }
  }
}

void kill_shark() {
  for (int i = 1; i <= M; i++) {
    if (!sharks[i].live) {
      continue;
    }
    int y = sharks[i].pos.first;
    int x = sharks[i].pos.second;

    if (board[y][x].v.size() >= 2) {
      sort(board[y][x].v.begin(), board[y][x].v.end());
      for (int j = 1; j < board[y][x].v.size(); j++) {
        sharks[board[y][x].v[j]].live = false;
      }
      board[y][x].v.erase(board[y][x].v.begin() + 1, board[y][x].v.end());
      board[y][x].smell.first = board[y][x].v[0];
    }
  }
}

int main() {
  int temp;
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &temp);
      if (temp != 0) {
        board[i][j].v.push_back(temp);
        sharks[temp].pos = {i, j};
        sharks[temp].live = true;
      }
      board[i][j].smell = {0, 0};
    }
  }
  for (int i = 1; i <= M; i++) {
    scanf("%d", &sharks[i].dir);
  }
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = 0; k < 4; k++) {
        scanf("%d", &sharks[i].weight[j][k]);
      }
    }
  }
  for (int time = 0; time <= 1000; time++) {
    if (check_sharks()) {
      printf("%d\n", time);
      return 0;
    }
    spread_smell(time);
    move_sharks(time);
    kill_shark();
  }
  printf("-1\n");
  return 0;
}