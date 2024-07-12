#include <bits/stdc++.h>
#define MAX 55
using namespace std;

int W, H;
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
bool board[MAX][MAX], visited[MAX][MAX];

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < H && 0 <= newx && newx < W;
}

void bfs(int a, int b) {
  queue<pair<int, int>> q;
  q.push({a, b});
  visited[a][b] = true;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 8; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      }
      if (!board[newy][newx]) {
        continue;
      }
      if (visited[newy][newx]) {
        continue;
      }
      q.push({newy, newx});
      visited[newy][newx] = true;
    }
  }
}

int main() {
  scanf("%d %d", &W, &H);
  while (W != 0 && H != 0) {
    int cnt = 0;
    int temp;
    memset(board, false, sizeof(board));
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        scanf("%d", &temp);
        if (temp == 1) {
          board[i][j] = true;
        } else {
          board[i][j] = false;
        }
      }
    }

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (board[i][j] && !visited[i][j]) {
          bfs(i, j);
          cnt++;
        }
      }
    }
    printf("%d\n", cnt);

    scanf("%d %d", &W, &H);
  }
}