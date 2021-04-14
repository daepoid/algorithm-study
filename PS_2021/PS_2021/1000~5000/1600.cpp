#include <bits/stdc++.h>
#define MAX 201
using namespace std;

int k, w, h;
int board[MAX][MAX];
// int visited[MAX][MAX];
bool visited[30][MAX][MAX];
int dy[12] = {0, -1, 0, 1, -1, -2, -2, -1, 1, 2, 2, 1};
int dx[12] = {1, 0, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < h && 0 <= newx && newx < w;
}

int bfs() {
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
  //   visited[0][0] = 0;
  visited[0][0][0] = true;

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int cnt = q.front().second.first;
    int horse = q.front().second.second;
    q.pop();

    if (y == h - 1 && x == w - 1) {
      return cnt;
    }

    for (int i = 0; i < 12; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      int newhorse = horse;
      if (i > 3) {
        newhorse = horse + 1;
      }

      if (!isvalid(newy, newx)) {
        continue;
      } else if (visited[newhorse][newy][newx]) {
        continue;
      } else if (k < newhorse) {
        continue;
      } else if (board[newy][newx] == 1) {
        continue;
      }
      visited[newhorse][newy][newx] = true;
      q.push(make_pair(make_pair(newy, newx), make_pair(cnt + 1, newhorse)));
    }
  }
  return -1;
}

int main() {
  scanf("%d", &k);
  scanf("%d %d", &w, &h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  int answer = bfs();
  printf("%d\n", answer);
}