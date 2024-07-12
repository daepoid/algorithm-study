#include <bits/stdc++.h>
#define MAX 102
using namespace std;

int T, N;
bool board[MAX][MAX], visited[MAX];
vector<pair<int, int>> v;

bool bfs() {
  queue<int> q;
  q.push(0);
  visited[0] = true;

  while (!q.empty()) {
    int num = q.front();
    q.pop();

    if (num == N + 1) {
      return true;
    }

    for (int i = 1; i < N + 2; i++) {
      if (visited[i]) {
        continue;
      }
      if (!board[num][i]) {
        continue;
      }
      visited[i] = true;
      q.push(i);
    }
  }
  return false;
}

int main() {
  scanf("%d", &T);
  while (T-- > 0) {
    int a, b;
    v.clear();
    memset(board, false, sizeof(board));
    memset(visited, false, sizeof(visited));
    scanf("%d", &N);
    scanf("%d %d", &a, &b);
    v.push_back({a, b});
    for (int i = 0; i < N; i++) {
      scanf("%d %d", &a, &b);
      v.push_back({a, b});
    }
    scanf("%d %d", &a, &b);
    v.push_back({a, b});
    for (int i = 0; i < N + 2; i++) {
      for (int j = i + 1; j < N + 2; j++) {
        int dist =
            abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
        if (dist <= 1000) {
          board[i][j] = true;
          board[j][i] = true;
        }
      }
    }
    bool flag = bfs();
    if (flag) {
      printf("happy\n");
    } else {
      printf("sad\n");
    }
  }
}