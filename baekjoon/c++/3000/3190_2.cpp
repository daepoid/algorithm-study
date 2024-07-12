#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int N, K, L, X;
int a, b;
char C[5];
bool visited[MAX][MAX], apples[MAX][MAX];
vector<pair<int, int>> cmd;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

int sol() {
  int idx = 0, cnt = 0;
  int newy = 0, newx = 0, d = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  visited[0][0] = true;

  while (true) {
    cnt++;
    newy += dy[d];
    newx += dx[d];
    if (!isvalid(newy, newx)) {
      return cnt;
    }
    if (visited[newy][newx]) {
      return cnt;
    }
    visited[newy][newx] = true;
    q.push(make_pair(newy, newx));
    if (apples[newy][newx]) {
      apples[newy][newx] = false;
    } else {
      visited[q.front().first][q.front().second] = false;
      q.pop();
    }

    if (cmd[idx].first == cnt) {
      if (cmd[idx].second = 'D') {
        d = (d + 3) % 4;
      } else if (cmd[idx].second == 'L') {
        d = (d + 1) % 4;
      }
      idx++;
    }
  }
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < K; i++) {
    scanf("%d %d", &a, &b);
    apples[a - 1][b - 1] = true;
  }
  scanf("%d", &L);

  for (int i = 0; i < L; i++) {
    scanf("%d %s", &X, C);
    cmd.push_back(make_pair(X, C[0]));
  }
  printf("%d\n", sol());
}