#include <bits/stdc++.h>
using namespace std;

int n, m, answer = -1;
char board[1001][1001];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int visited[1001][1001][2];

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

void bfs() {
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
  visited[0][0][0] = true;

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int chance = q.front().second.first;
    int cnt = q.front().second.second;
    q.pop();

    if (y == n - 1 && x == m - 1) {
      answer = cnt;
      return;
    }

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (!isvalid(newy, newx)) {
        continue;
      }
      if (board[newy][newx] == '1' && chance == 0) {
        visited[newy][newx][1] = true;
        q.push(
            make_pair(make_pair(newy, newx), make_pair(chance + 1, cnt + 1)));
      } else if (board[newy][newx] == '0' &&
                 visited[newy][newx][chance] == false) {
        visited[newy][newx][chance] = true;
        q.push(make_pair(make_pair(newy, newx), make_pair(chance, cnt + 1)));
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", board[i]);
  }
  bfs();
  printf("%d\n", answer);
}