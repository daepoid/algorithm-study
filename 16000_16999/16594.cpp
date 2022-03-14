#include <bits/stdc++.h>
#define MAX 8
using namespace std;

int answer = 0;
char board[MAX][MAX], walls[MAX][MAX][MAX];
vector<pair<int, int>> wallv;

int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < MAX && 0 <= newx && newx < MAX;
}

void makeboard() {
  for (int i = 0; i < wallv.size(); i++) {
    int y = wallv[i].first;
    int x = wallv[i].second;
    int t = 1;

    while (true) {
      int newy = y + 1;
      int newx = x;
      if (newy >= MAX) {
        break;
      }
      walls[t][newy][newx] = '#';
      t++;
      y = newy;
      x = newx;
    }
  }
}

bool isfinish(int y, int turn) {
  for (int i = y - 1; i >= 0; i--) {
    for (int j = 0; j < MAX; j++) {
      if (walls[turn][i][j] == '#') {
        return false;
      }
    }
  }
  return true;
}

void bfs() {
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(7, 0), 0));

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int turn = q.front().second;
    q.pop();

    if (y == 0) {
      answer = 1;
      return;
    } else if (isfinish(y, turn)) {
      answer = 1;
      return;
    }

    for (int i = 0; i < 9; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      int newturn = turn + 1;

      if (!isvalid(newy, newx)) {
        continue;
      } else if (walls[turn][newy][newx] == '#' ||
                 walls[turn + 1][newy][newx] == '#') {
        continue;
      }

      q.push(make_pair(make_pair(newy, newx), turn + 1));
    }
  }
}

bool isimpossible() {
  for (int i = 0; i < MAX - 1; i++) {
    int cnt = 0;
    for (int j = 0; j < MAX; j++) {
      if (board[i][j] == '#') {
        cnt++;
      }
    }
    if (cnt == MAX) {
      return true;
    }
  }
  return false;
}

int main() {
  for (int i = 0; i < MAX; i++) {
    scanf("%s", board[i]);
    for (int j = 0; j < MAX; j++) {
      if (board[i][j] == '#') {
        walls[0][i][j] = '#';
        wallv.push_back(make_pair(i, j));
      }
    }
  }

  for (int k = 0; k < MAX; k++) {
    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        if (walls[k][i][j] == '#') {
          continue;
        }
        walls[k][i][j] = '.';
      }
    }
  }

  if (wallv.size() == 0) {
    printf("1\n");
    return 0;
  }
  if (isimpossible()) {
    printf("0\n");
    return 0;
  }
  makeboard();
  bfs();
  printf("%d\n", answer);
}