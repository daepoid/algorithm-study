#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int N, L, R, answer = 0;
int board[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool visited[MAX][MAX];
bool flag = true;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

bool can_comb(int y, int x) {
  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (isvalid(newy, newx)) {
      if (L <= abs(board[y][x] - board[newy][newx]) &&
          abs(board[y][x] - board[newy][newx]) <= R) {
        return true;
      }
    }
  }
  return false;
}

bool ismovable(int y, int x, int newy, int newx) {
  if (L <= abs(board[y][x] - board[newy][newx]) &&
      abs(board[y][x] - board[newy][newx]) <= R) {
    return true;
  }
  return false;
}

void bfs(int y, int x) {
  queue<pair<int, int>> q, nq;
  q.push(make_pair(y, x));
  nq.push(make_pair(y, x));
  visited[y][x] = true;
  int cnt = 0;
  int sum = 0;

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    sum += board[y][x];
    cnt++;
    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      }
      if (visited[newy][newx]) {
        continue;
      }
      if (ismovable(y, x, newy, newx)) {
        visited[newy][newx] = true;
        q.push(make_pair(newy, newx));
        nq.push(make_pair(newy, newx));
      }
    }
  }
  int val = sum / cnt;
  while (!nq.empty()) {
    y = nq.front().first;
    x = nq.front().second;
    nq.pop();
    board[y][x] = val;
  }
}

int main() {
  scanf("%d %d %d", &N, &L, &R);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  while (flag) {
    flag = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!visited[i][j] && can_comb(i, j)) {
          bfs(i, j);
          flag = true;
        }
      }
    }
    if (flag) {
      answer++;
    }
    memset(visited, false, sizeof(visited));
  }
  printf("%d\n", answer);
}