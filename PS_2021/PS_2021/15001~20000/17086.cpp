#include <bits/stdc++.h>
#define MAX 51
#define INF 987654321
using namespace std;

int board[MAX][MAX], dist[MAX][MAX], n, m;
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int answer = 0;
vector<pair<int, int>> v;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

void bfs(int y, int x) {
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(y, x), 0));

  while (!q.empty()) {
    y = q.front().first.first;
    x = q.front().first.second;
    int cnt = q.front().second;
    q.pop();

    for (int i = 0; i < 8; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (!isvalid(newy, newx)) {
        continue;
      } else if (board[newy][newx] == 1) {
        continue;
      } else if (dist[newy][newx] <= cnt + 1) {
        continue;
      }
      dist[newy][newx] = cnt + 1;
      q.push(make_pair(make_pair(newy, newx), cnt + 1));
    }
  }
}

void find_answer() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j] != INF && answer < dist[i][j]) {
        answer = dist[i][j];
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
      dist[i][j] = INF;
      if (board[i][j] == 1) {
        v.push_back(make_pair(i, j));
      }
    }
  }
  for (int i = 0; i < v.size(); i++) {
    bfs(v[i].first, v[i].second);
  }
  find_answer();
  printf("%d\n", answer);
}