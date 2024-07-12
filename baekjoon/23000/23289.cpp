#include <bits/stdc++.h>
#define MAX 22

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

using namespace std;

int R, C, K, W;
int chocolate = 0;
int board[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int wind_dx[4][3] = {{-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1}};
int wind_dy[4][3] = {{1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {-1, 0, 1}};

bool wall_board[MAX][MAX][4];
vector<pair<int, int>> search_pos;
vector<pair<pair<int, int>, int>> heater;

bool check_wall(int x, int y, int dir, int pos) {
  if (pos == 0) {
    if (dir == RIGHT) {
      if (!wall_board[x][y][UP] && !wall_board[x - 1][y][dir]) {
        return true;
      }
    } else if (dir == LEFT) {
      if (!wall_board[x][y][UP] && !wall_board[x - 1][y][dir]) {
        return true;
      }
    } else if (dir == UP) {
      if (!wall_board[x][y][LEFT] && !wall_board[x][y - 1][dir]) {
        return true;
      }
    } else if (dir == DOWN) {
      if (!wall_board[x][y][LEFT] && !wall_board[x][y - 1][dir]) {
        return true;
      }
    }
  } else if (pos == 1) {
    if (!wall_board[x][y][dir]) {
      return true;
    }
  } else if (pos == 2) {
    if (dir == RIGHT) {
      if (!wall_board[x][y][DOWN] && !wall_board[x + 1][y][dir]) {
        return true;
      }
    } else if (dir == LEFT) {
      if (!wall_board[x][y][DOWN] && !wall_board[x + 1][y][dir]) {
        return true;
      }
    } else if (dir == UP) {
      if (!wall_board[x][y][RIGHT] && !wall_board[x][y + 1][dir]) {
        return true;
      }
    } else if (dir == DOWN) {
      if (!wall_board[x][y][RIGHT] && !wall_board[x][y + 1][dir]) {
        return true;
      }
    }
  }
  return false;
}

bool is_valid(int newx, int newy) {
  return 0 < newx && newx < R + 1 && 0 < newy && newy < C + 1;
}

void spread(int ori_x, int ori_y, int dir) {
  bool visited[MAX][MAX] = {
      false,
  };

  dir--;
  ori_x += dx[dir];
  ori_y += dy[dir];

  if (!is_valid(ori_x, ori_y)) {
    return;
  }

  queue<pair<pair<int, int>, int>> q;
  q.push({{ori_x, ori_y}, 5});

  while (!q.empty()) {
    int x = q.front().first.first;
    int y = q.front().first.second;
    int wind = q.front().second;
    q.pop();

    board[x][y] += wind;

    if (wind == 1) {
      continue;
    }

    for (int i = 0; i < 3; i++) {
      int newx = x + wind_dx[dir][i];
      int newy = y + wind_dy[dir][i];

      if (is_valid(newx, newy)) {
        if (!visited[newx][newy] && check_wall(x, y, dir, i)) {
          visited[newx][newy] = true;
          q.push({{newx, newy}, wind - 1});
        }
      }
    }
  }
}

void heater_wind() {
  for (int i = 0; i < heater.size(); i++) {
    spread(heater[i].first.first, heater[i].first.second, heater[i].second);
  }
}

void change_temperature() {
  int temp[MAX][MAX] = {
      0,
  };

  for (int i = 1; i < R + 1; i++) {
    for (int j = 1; j < C + 1; j++) {
      for (int k = 0; k < 2; k++) {
        int dir = k * 3;

        int newx = i + dx[dir];
        int newy = j + dy[dir];

        if (is_valid(newx, newy) && !wall_board[i][j][dir]) {
          int val = abs(board[i][j] - board[newx][newy]) / 4;
          if (board[i][j] > board[newx][newy]) {
            temp[i][j] -= val;
            temp[newx][newy] += val;
          } else if (board[i][j] < board[newx][newy]) {
            temp[i][j] += val;
            temp[newx][newy] -= val;
          }
        }
      }
    }
  }

  for (int i = 1; i < R + 1; i++) {
    for (int j = 1; j < C + 1; j++) {
      board[i][j] += temp[i][j];
    }
  }
}

void decrease_temperature() {
  for (int i = 1; i < C + 1; i++) {
    if (board[1][i] > 0) {
      board[1][i]--;
    }
    if (board[R][i] > 0) {
      board[R][i]--;
    }
  }
  for (int i = 2; i < R; i++) {
    if (board[i][1] > 0) {
      board[i][1]--;
    }
    if (board[i][C] > 0) {
      board[i][C]--;
    }
  }
}

void eat_chocolate() { chocolate++; }

bool check_temperature() {
  for (int i = 0; i < search_pos.size(); i++) {
    int x = search_pos[i].first;
    int y = search_pos[i].second;
    if (board[x][y] < K) {
      return false;
    }
  }
  return true;
}

int main() {
  int temp;
  scanf("%d %d %d", &R, &C, &K);
  for (int i = 1; i < R + 1; i++) {
    for (int j = 1; j < C + 1; j++) {
      scanf("%d", &temp);
      if (0 < temp && temp < 5) {
        heater.push_back({{i, j}, temp});
      } else if (temp == 5) {
        search_pos.push_back({i, j});
      }
    }
  }

  int x, y, t;
  scanf("%d", &W);
  for (int i = 0; i < W; i++) {
    scanf("%d %d %d", &x, &y, &t);
    if (t == 0) {
      wall_board[x][y][UP] = true;
      wall_board[x - 1][y][DOWN] = true;
    } else if (t == 1) {
      wall_board[x][y][RIGHT] = true;
      wall_board[x][y + 1][LEFT] = true;
    }
  }

  while (chocolate < 101) {
    heater_wind();
    change_temperature();
    decrease_temperature();
    eat_chocolate();

    if (check_temperature()) {
      break;
    }
  }
  printf("%d\n", chocolate);

  return 0;
}