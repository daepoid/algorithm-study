#include <bits/stdc++.h>
#define MAX 3001
using namespace std;

int n;
bool visited[MAX], flag = false;
int cycle[MAX];
vector<int> station[MAX];

void dfs(int origin, int now, int cnt) {
  if (cnt >= 2 && origin == now) {
    flag = true;
    return;
  }
  for (int i = 0; i < station[now].size(); i++) {
    int next = station[now][i];
    if (visited[next]) {
      continue;
    } else if (origin == next && cnt < 2) {
      continue;
    }
    visited[next] = true;
    dfs(origin, next, cnt + 1);
    // visited[next] = false;
    if (flag) {
      cycle[now] = 0;
      return;
    }
  }
}

void bfs(int origin) {
  //   bool bfsvisited[MAX];
  //   memset(bfsvisited, false, sizeof(bfsvisited));
  queue<pair<int, int>> q;

  q.push(make_pair(origin, 1));
  while (!q.empty()) {
    int now = q.front().first;
    int cnt = q.front().second;
    q.pop();
    // bfsvisited[now] = true;

    for (int i = 0; i < station[now].size(); i++) {
      int next = station[now][i];
      if (cycle[next] == 0) {
        cycle[origin] = cnt;
        return;
      }
      q.push(make_pair(next, cnt + 1));
      //   if (!bfsvisited[i]) {
      //     q.push(make_pair(next, cnt + 1));
      //   }
    }
  }
}

int main() {
  int a, b;
  scanf("%d", &n);
  memset(cycle, -1, sizeof(cycle));

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    station[a].push_back(b);
    station[b].push_back(a);
  }
  for (int i = 1; i < n + 1; i++) {
    if (cycle[i] == -1) {
      flag = false;
      dfs(i, i, 0);
    }
  }
  for (int i = 1; i < n + 1; i++) {
    int dist = -1;
    if (cycle[i] < 0) {
      bfs(i);
    }
    dist = cycle[i];
    if (i == n) {
      printf("%d\n", dist);
    } else {
      printf("%d ", dist);
    }
  }
}