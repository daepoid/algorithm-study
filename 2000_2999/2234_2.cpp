#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int M, N, max_room_size = 0;
int board[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
bool visited[MAX][MAX];

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

void bfs(int y, int x) {
  int rs = 1;
  queue<pair<int, int>> q;
  q.push(make_pair(y, x));
  visited[y][x] = true;

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();
    int wall_num = 1;

    for (int i = 0; i < 4; i++) {
      if ((board[y][x] & wall_num) == 0) {
        int newy = y + dy[i];
        int newx = x + dx[i];
        if (isvalid(newy, newx) && !visited[newy][newx]) {
          rs++;
          visited[newy][newx] = true;
          q.push(make_pair(newy, newx));
        }
      }
      wall_num *= 2;
    }
  }
  max_room_size = max(max_room_size, rs);
}

int main() {
  scanf("%d %d", &M, &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  int room_count = 0;
  // 1번 2번
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visited[i][j]) {
        bfs(i, j);
        room_count++;
      }
    }
  }
  printf("%d\n", room_count);
  printf("%d\n", max_room_size);

  // 3번
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int wall_num = 1;
      for (int k = 0; k < 4; k++) {
        if ((board[i][j] & wall_num) != 0) {
          memset(visited, false, sizeof(visited));
          board[i][j] -= wall_num;
          bfs(i, j);
          board[i][j] += wall_num;
        }
        wall_num *= 2;
      }
    }
  }
  printf("%d\n", max_room_size);
}