#include <bits/stdc++.h>
#define MAX 1000111
using namespace std;

bool visited[MAX];

int f, s, g, u, d;
int answer = -1;

void bfs() {
  queue<pair<int, int>> q;
  q.push(make_pair(s, 0));

  while (!q.empty()) {
    int now = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if (now == g) {
      answer = cnt;
      return;
    }
    for (int i = 0; i < 2; i++) {
      int next;
      if (i == 0) {
        next += u;
      } else if (i == 1) {
        next -= d;
      }
      if (next > f || next < 0) {
        continue;
      } else if (visited[next]) {
        continue;
      }
      visited[next] = true;
      q.push(make_pair(next, cnt + 1));
    }
  }
}

int main() {
  scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
  if (s > g && d == 0) {
    printf("use the stairs\n");
    return 0;
  } else if (s < g && u == 0) {
    printf("use the stairs\n");
    return 0;
  }
  bfs();
  if (answer == -1) {
    printf("use the stairs\n");
  } else {
    printf("%d\n", answer);
  }
  return 0;
}