#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int n, l, r;
int answer = 0;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < n;
}

bool ismovable(int y, int x, int newy, int newx) {
  int temp = abs(board[y][x] - board[newy][newx]);
  if (l <= temp && temp <= r) {
    return true;
  } else {
    return false;
  }
}

void bfs(int y, int x) {
  int sum = 0;
  int cnt = 0;
  queue<pair<int, int>> q, vq;
  q.push(make_pair(y, x));
  vq.push(make_pair(y, x));
  visited[y][x] = true;

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
      } else if (visited[newy][newx]) {
        continue;
      } else if (!ismovable(y, x, newy, newx)) {
        continue;
      }
      visited[newy][newx] = true;
      q.push(make_pair(newy, newx));
      vq.push(make_pair(newy, newx));
    }
  }
  int value = sum / cnt;
  while (!vq.empty()) {
    board[vq.front().first][vq.front().second] = value;
    vq.pop();
  }
}

int main() {
  int answer = 0;
  bool moveflag = true;
  scanf("%d %d %d", &n, &l, &r);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  while (moveflag) {
    moveflag = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) {
          bool movable = false;
          for (int k = 0; k < 4; k++) {
            int newy = i + dy[k];
            int newx = j + dx[k];
            if (ismovable(i, j, newy, newx)) {
              movable = true;
              break;
            }
          }
          if (movable) {
            bfs(i, j);
            moveflag = true;
          }
        }
      }
    }
    if (moveflag) {
      answer++;
    }
    memset(visited, false, sizeof(visited));
  }
  printf("%d\n", answer);
}