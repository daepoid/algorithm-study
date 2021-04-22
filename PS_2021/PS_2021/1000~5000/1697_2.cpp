#include <bits/stdc++.h>
#define MAX 222222
using namespace std;

int visited[MAX], N, K;

void bfs(int n, int k) {
  queue<int> q;
  q.push(N);
  visited[N] = 1;

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    if (now == k) {
      return;
    }
    if (0 <= now - 1 && visited[now - 1] == 0) {
      visited[now - 1] = visited[now] + 1;
      q.push(now - 1);
    }
    if (now + 1 <= MAX && visited[now + 1] == 0) {
      visited[now + 1] = visited[now] + 1;
      q.push(now + 1);
    }
    if (now * 2 < MAX && visited[now * 2] == 0) {
      visited[now * 2] = visited[now] + 1;
      q.push(now * 2);
    }
  }
}

int main() {
  scanf("%d %d", &N, &K);
  bfs(N, K);
  printf("%d\n", visited[K] - 1);
  return 0;
}