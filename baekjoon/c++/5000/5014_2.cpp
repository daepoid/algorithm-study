#include <bits/stdc++.h>
#define MAX 1000111
using namespace std;

int visited[MAX];
int f, s, g, u, d;

void bfs() {
  queue<pair<int, int>> q;
  q.push(make_pair(s, 0));
  visited[s] = 0;

  while (!q.empty()) {
    int now = q.front().first;
    int cnt = q.front().second;
    q.pop();

    for (int i = 0; i < 2; i++) {
      int next = now;
      if (i == 0) {
        next = now + u;
      } else if (i == 1) {
        next = now - d;
      }
      if (0 < next && next < f + 1) {
        if (visited[next] == -1) {
          visited[next] = cnt + 1;
        } else if (visited[next] > cnt + 1) {
          visited[next] = min(visited[next], cnt + 1);
        } else {
          continue;
        }
        q.push(make_pair(next, cnt + 1));
      }
    }
  }
}

int main() {
  scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
  memset(visited, -1, sizeof(visited));

  if (s > g && d == 0) {
    printf("use the stairs\n");
    return 0;
  } else if (s < g && u == 0) {
    printf("use the stairs\n");
    return 0;
  }
  bfs();
  if (visited[g] == -1) {
    printf("use the stairs\n");
  } else {
    printf("%d\n", visited[g]);
  }
  return 0;
}