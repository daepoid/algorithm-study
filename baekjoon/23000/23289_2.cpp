#include <bits/stdc++.h>
#define MAX 22
using namespace std;

int R, C, K, W;
int board[MAX][MAX];
bool wall_board[MAX][MAX][4];

vector<pair<int, int>> search_pos;
vector<pair<pair<int, int>, int>> heater;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int wind_dx[4][3] = {{-1, 0, 1}, {-1, 0, 1}, {1, 1, 1}, {-1, -1, -1}};
int wind_dy[4][3] = {{1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {-1, 0, 1}};

int chocolate = 0;

void printBoard() {
  printf("\n");
  printf("Chocolate: %d\n", chocolate);
  for (int i = 1; i < R + 1; i++) {
    for (int j = 1; j < C + 1; j++) {
      printf("%2d ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

bool isValid(int newx, int newy) {
  return 0 < newx && newx < R + 1 && 0 < newy && newy < C + 1;
}

bool checkWall(int x, int y, int d, int dir) {
  if (dir == 1) {
    if (!wall_board[x][y][d]) {
      return true;
    }
  } else if (dir == 0) {
    if (d == 0) {
      if (!wall_board[x][y][3] && !wall_board[x - 1][y][0]) {
        return true;
      }
    } else if (d == 1) {
      if (!wall_board[x][y][3] && !wall_board[x - 1][y][1]) {
        return true;
      }
    } else if (d == 2) {
      if (!wall_board[x][y][1] && !wall_board[x][y - 1][2]) {
        return true;
      }
    } else if (d == 3) {
      if (!wall_board[x][y][1] && !wall_board[x][y - 1][3]) {
        return true;
      }
    }
  } else if (dir == 2) {
    if (d == 0) {
      if (!wall_board[x][y][2] && !wall_board[x + 1][y][0]) {
        return true;
      }
    } else if (d == 1) {
      if (!wall_board[x][y][2] && !wall_board[x + 1][y][1]) {
        return true;
      }
    } else if (d == 2) {
      if (!wall_board[x][y][0] && !wall_board[x][y + 1][2]) {
        return true;
      }
    } else if (d == 3) {
      if (!wall_board[x][y][0] && !wall_board[x][y + 1][3]) {
        return true;
      }
    }
  }
  return false;
}

int change_dir(int d) {
  switch (d) {
  case 1:
    return 0;
  case 2:
    return 1;
  case 3:
    return 3;
  case 4:
    return 2;
  }
}

void spread(int x, int y, int d) {
  bool temp[MAX][MAX] = {
      false,
  };

  d = change_dir(d);
  x += dx[d];
  y += dy[d];

  if (!isValid(x, y)) {
    return;
  }

  queue<pair<pair<int, int>, int>> q;
  q.push({{x, y}, 5});

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
      int newx = x + wind_dx[d][i];
      int newy = y + wind_dy[d][i];

      if (isValid(newx, newy)) {
        if (!temp[newx][newy] && checkWall(x, y, d, i)) {
          temp[newx][newy] = true;
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
        int dir = k * 2;

        int newx = i + dx[dir];
        int newy = j + dy[dir];

        if (isValid(newx, newy)) {
          if (!wall_board[i][j][dir]) {
            int val = abs(board[i][j] - board[newx][newy]) / 4;

            if (board[i][j] > board[newx][newy]) {
              temp[i][j] -= val;
              temp[newx][newy] += val;
            } else {
              temp[i][j] += val;
              temp[newx][newy] -= val;
            }
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
      if (temp != 0 && temp != 5) {
        heater.push_back({{i, j}, temp});
      } else if (temp == 5) {
        search_pos.push_back({i, j});
      }
    }
  }

  scanf("%d", &W);
  for (int i = 0; i < W; i++) {
    int x, y, t;
    scanf("%d %d %d", &x, &y, &t);

    if (t == 0) {
      wall_board[x][y][3] = true;
      wall_board[x - 1][y][2] = true;
    } else {
      wall_board[x][y][0] = true;
      wall_board[x][y + 1][1] = true;
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