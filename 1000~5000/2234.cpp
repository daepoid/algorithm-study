#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int n, m;
int board[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
bool visited[MAX][MAX];

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

int bfs(int y, int x) {
  int room_size = 1;
  queue<pair<int, int>> q;
  q.push(make_pair(y, x));
  visited[y][x] = true;

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();
    int wall_check = 1;

    for (int i = 0; i < 4; i++) {
      if ((board[y][x] & wall_check) != wall_check) {
        int newy = y + dy[i];
        int newx = x + dx[i];
        if (isvalid(newy, newx) && !visited[newy][newx]) {
          room_size++;
          visited[newy][newx] = true;
          q.push(make_pair(newy, newx));
        }
      }
      wall_check *= 2;
    }
  }
  return room_size;
}

int main() {
  int room_cnt = 0, biggest = 0;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        biggest = max(biggest, bfs(i, j));
        room_cnt++;
      }
    }
  }
  printf("%d\n", room_cnt);
  printf("%d\n", biggest);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 1; k <= 8; k *= 2) {
        if ((board[i][j] & k) == k) {
          memset(visited, false, sizeof(visited));
          board[i][j] -= k;
          biggest = max(biggest, bfs(i, j));
          board[i][j] += k;
        }
      }
    }
  }
  printf("%d\n", biggest);
}