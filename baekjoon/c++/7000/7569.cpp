#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N, M, H, answer = 0;
int board[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int dz[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dx[6] = {1, 0, -1, 0, 0, 0};
vector<pair<pair<int, int>, int>> v;

bool isvalid(int newz, int newy, int newx) {
  return 0 <= newz && newz < H && 0 <= newy && newy < N && 0 <= newx &&
         newx < M;
}

void bfs() {
  queue<pair<pair<int, int>, pair<int, int>>> q;
  for (int i = 0; i < v.size(); i++) {
    q.push({{v[i].first.first, v[i].first.second}, {v[i].second, 0}});
    visited[v[i].second][v[i].first.first][v[i].first.second] = true;
  }

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int z = q.front().second.first;
    int cnt = q.front().second.second;
    q.pop();

    for (int i = 0; i < 6; i++) {
      int newz = z + dz[i];
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newz, newy, newx)) {
        continue;
      }
      if (visited[newz][newy][newx]) {
        continue;
      }
      if (board[newz][newy][newx] != 0) {
        continue;
      }
      visited[newz][newy][newx] = true;
      board[newz][newy][newx] = 1;
      q.push({{newy, newx}, {newz, cnt + 1}});
      answer = max(answer, cnt + 1);
    }
  }
}

int main() {
  scanf("%d %d %d", &M, &N, &H);
  for (int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        scanf("%d", &board[k][i][j]);
        if (board[k][i][j] == 1) {
          v.push_back({{i, j}, k});
        }
      }
    }
  }
  bfs();
  for (int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board[k][i][j] == 0) {
          printf("-1\n");
          return 0;
        }
      }
    }
  }
  printf("%d\n", answer);
}