#include <bits/stdc++.h>
#define MAX 222222
using namespace std;

int visited[MAX], route[MAX], N, K;

void bfs() {
  queue<int> q;
  q.push(N);
  visited[N] = 1;

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    if (now == K) {
      return;
    }
    if (0 <= now - 1 && visited[now - 1] == 0) {
      visited[now - 1] = visited[now] + 1;
      route[now - 1] = now;
      q.push(now - 1);
    }
    if (now + 1 <= MAX && visited[now + 1] == 0) {
      visited[now + 1] = visited[now] + 1;
      route[now + 1] = now;
      q.push(now + 1);
    }
    if (now * 2 < MAX && visited[now * 2] == 0) {
      visited[now * 2] = visited[now] + 1;
      route[now * 2] = now;
      q.push(now * 2);
    }
  }
}

int main() {
  scanf("%d %d", &N, &K);
  bfs();
  printf("%d\n", visited[K] - 1);

  vector<int> arr;
  for (int i = K; i != N; i = route[i]) {
    arr.push_back(i);
  }
  arr.push_back(N);
  reverse(arr.begin(), arr.end());
  for (int i = 0; i < arr.size(); i++) {
    if (i == arr.size() - 1) {
      printf("%d\n", arr[i]);
    } else {
      printf("%d ", arr[i]);
    }
  }
  return 0;
}