#include <bits/stdc++.h>
#define INF 987654321
#define MAX 5
using namespace std;

bool visited[MAX][MAX][MAX];
int board[MAX][MAX][MAX], temp[MAX][MAX][MAX], answer = INF;
int dz[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dx[6] = {1, 0, -1, 0, 0, 0};
int turn[MAX] = {
    -1,
};
int maze[MAX] = {
    -1,
};

void copy_board() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      for (int k = 0; k < MAX; k++) {
      }
    }
  }
}

bool isvalid(int newz, int newy, int newx) {
  return 0 <= newz && newz < MAX && 0 <= newy && newy < MAX && 0 <= newx &&
         newx < MAX;
}

int bfs(int newboard[MAX][MAX][MAX]) {
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push({{0, 0}, {0, 0}});
  visited[0][0][0] = true;

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int z = q.front().second.first;
    int cnt = q.front().second.second;
    q.pop();

    if (z == MAX - 1 && y == MAX - 1 && x == MAX - 1) {
      return cnt;
    }
    for (int i = 0; i < 6; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      int newz = z + dz[i];

      if (isvalid(newz, newy, newx) && newboard[newz][newy][newx] == 1 &&
          !visited[newz][newy][newx]) {
        visited[newz][newy][newx] = true;
        q.push({{newy, newx}, {newz, cnt + 1}});
      }
    }
  }
  return -1;
}

void rotate_boards(int cnt) {
  if (cnt == MAX) {
    make_board();
    return;
  }
  for (int i = 0; i < MAX;)
}

int main() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      for (int k = 0; k < MAX; k++) {
        scanf("%d", &board[i][j][k]);
      }
    }
  }
  // 불가능한 조건 확인

  rotate_boards(0);

  if (answer == INF) {
    printf("-1\n");
  } else {
    printf("%d\n", answer);
  }
}