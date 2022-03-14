#include <bits/stdc++.h>
#define MAX 111
using namespace std;

int M, N, K;
bool board[MAX][MAX], visited[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector<int> v;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < M && 0 <= newx && newx < N;
}

void bfs(int a, int b) {
  int cnt = 1;
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
      if (board[newy][newx]) {
        continue;
      }
      if (visited[newy][newx]) {
        continue;
      }
      visited[newy][newx] = true;
      cnt++;
      q.push({newy, newx});
    }
  }
  v.push_back(cnt);
}

int main() {
  scanf("%d %d %d", &M, &N, &K);
  for (int i = 0; i < K; i++) {
    int ly, lx, ry, rx;
    scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
    for (int i = ly; i < ry; i++) {
      for (int j = lx; j < rx; j++) {
        board[i][j] = true;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (!board[i][j] && !visited[i][j]) {
        bfs(i, j);
        cnt++;
      }
    }
  }
  printf("%d\n", cnt);
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (i == v.size() - 1) {
      printf("%d\n", v[i]);
    } else {
      printf("%d ", v[i]);
    }
  }
}