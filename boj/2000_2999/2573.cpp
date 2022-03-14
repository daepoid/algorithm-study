#include <bits/stdc++.h>
#define MAX 301
using namespace std;

int N, M;
int board[MAX][MAX], newboard[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool visited[MAX][MAX];
vector<pair<int, int>> v;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

void bfs(int a, int b) {
  queue<pair<int, int>> q;
  q.push({a, b});
  visited[a][b] = true;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (!isvalid(newy, newx)) {
        continue;
      }
      if (visited[newy][newx]) {
        continue;
      }
      if (board[newy][newx] != 0) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
          int yy = newy + dy[j];
          int xx = newx + dx[j];
          if (!isvalid(yy, xx)) {
            continue;
          }
          if (board[yy][xx] != 0) {
            continue;
          }
          cnt++;
        }
        visited[newy][newx] = true;
        newboard[newy][newx] = cnt;
      } else {
        visited[newy][newx] = true;
        newboard[newy][newx] = 0;
        q.push({newy, newx});
      }
    }
  }
}

void bfs_ice(int a, int b) {
  queue<pair<int, int>> q;
  q.push({a, b});
  visited[a][b] = true;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (!isvalid(newy, newx)) {
        continue;
      }
      if (visited[newy][newx]) {
        continue;
      }
      if (board[newy][newx] == 0) {
        continue;
      }
      visited[newy][newx] = true;
      q.push({newy, newx});
    }
  }
}

bool isoneblock() {
  v.clear();
  int cnt = 0;
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 0) {
        continue;
      } else {
        v.push_back({i, j});
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visited[i][j] && board[i][j] > 0) {
        bfs_ice(i, j);
        cnt++;
      }
    }
  }
  if (cnt > 1) {
    return false;
  } else {
    return true;
  }
}

bool iszero() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] != 0) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  int time = 0;
  while (true) {
    if (!isoneblock()) {
      break;
    }
    if (iszero()) {
      time = 0;
      break;
    }
    memset(newboard, 0, sizeof(newboard));
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board[i][j] == 0 && !visited[i][j]) {
          bfs(i, j);
        }
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        board[i][j] = max(0, board[i][j] - newboard[i][j]);
      }
    }
    time++;
  }
  printf("%d\n", time);
}