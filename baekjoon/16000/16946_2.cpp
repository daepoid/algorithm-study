#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int N, M, num = 1;
char board[MAX][MAX];
int nboard[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector<int> v;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

void bfs(int y, int x, int num) {
  int cnt = 1;
  queue<pair<int, int>> q;
  q.push(make_pair(y, x));
  nboard[y][x] = num;

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      }
      if (nboard[newy][newx] != 0) {
        continue;
      }
      if (board[newy][newx] != '0') {
        continue;
      }
      nboard[newy][newx] = num;
      q.push(make_pair(newy, newx));
      cnt++;
    }
  }
  v.push_back(cnt);
}

int count_space(int y, int x) {
  set<int> s;
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (isvalid(newy, newx)) {
      s.insert(nboard[newy][newx]);
    }
  }
  for (auto it : s) {
    sum += v[it];
  }
  return (sum + 1) % 10;
}

int main() {
  v.push_back(0);
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%s", board[i]);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == '0' && nboard[i][j] == 0) {
        bfs(i, j, num);
        num++;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == '0') {
        printf("0");
      } else {
        printf("%d", count_space(i, j));
      }
    }
    printf("\n");
  }
}