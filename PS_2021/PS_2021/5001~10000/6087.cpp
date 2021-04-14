#include <bits/stdc++.h>
#define MAX 101
#define INF 987654321
using namespace std;

int n, m, answer = 2100000000;
char board[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int visited[MAX][MAX];
vector<pair<int, int>> node;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

void bfs() {
  queue<pair<pair<int, int>, pair<int, int>>> q;
  int y = node[0].first;
  int x = node[0].second;
  int before = -1;
  int cnt = 0;
  q.push(make_pair(make_pair(y, x), make_pair(-1, cnt)));
  visited[y][x] = INF;

  while (!q.empty()) {
    y = q.front().first.first;
    x = q.front().first.second;
    before = q.front().second.first;
    cnt = q.front().second.second;
    q.pop();

    // if (y == node[1].first && x == node[1].second) {
    //   answer = min(answer, cnt);
    //   // return;
    // }

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx) || board[newy][newx] == '*') {
        continue;
      }

      if (before == -1 || before == i) {
        q.push(make_pair(make_pair(newy, newx), make_pair(i, cnt)));
        visited[newy][newx] = min(visited[newy][newx], cnt);
      } else if (before % 2 == i % 2) {
        continue;
      } else if (visited[newy][newx] < cnt + 1) {
        continue;
      } else {
        q.push(make_pair(make_pair(newy, newx), make_pair(i, cnt + 1)));
        visited[newy][newx] = min(visited[newy][newx], cnt + 1);
      }
    }
  }
}

void printboard() {
  printf("\n\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j == m - 1) {
        printf("%d\n", board[i][j]);
      } else {
        printf("%d ", board[i][j]);
      }
    }
  }
}

int main() {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", board[i]);
    for (int j = 0; j < m; j++) {
      visited[i][j] = INF;

      if (board[i][j] == 'C') {
        node.push_back(make_pair(i, j));
      }
    }
  }
  bfs();
  printf("%d\n", visited[node[1].first][node[1].second]);
}