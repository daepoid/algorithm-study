#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N, board[MAX][MAX], newboard[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool visited[MAX][MAX];
vector<pair<int, int>> v;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
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
      if (newboard[newy][newx] == 0) {
        continue;
      }
      if (visited[newy][newx]) {
        continue;
      }
      visited[newy][newx] = true;
      q.push({newy, newx});
    }
  }
}

int main() {
  int max_high = 0, answer = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
      max_high = max(max_high, board[i][j]);
    }
  }
  for (int k = 0; k <= max_high; k++) {
    memset(visited, false, sizeof(visited));
    memcpy(newboard, board, sizeof(board));
    v.clear();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (newboard[i][j] <= k) {
          newboard[i][j] = 0;
        } else {
          v.push_back({i, j});
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
      int y = v[i].first;
      int x = v[i].second;

      if (!visited[y][x]) {
        cnt++;
        bfs(y, x);
      }
    }
    answer = max(answer, cnt);
  }
  printf("%d\n", answer);
}