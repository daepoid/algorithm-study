#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define MAX 100001
using namespace std;

int n, k, pos;
int visited[MAX];
queue<int> q;

void bfs() {
  q.push(n);
  visited[n] = 1;
  while (!q.empty()) {
    pos = q.front();
    q.pop();
    if (pos == k) {
      return;
    }
    if (0 <= pos - 1 && visited[pos - 1] == 0) {
      visited[pos - 1] = visited[pos] + 1;
      q.push(pos - 1);
    } else if (0 <= pos - 1) {
      visited[pos - 1] = min(visited[pos - 1], visited[pos] + 1);
    }
    if (pos + 1 < MAX && visited[pos + 1] == 0) {
      visited[pos + 1] = visited[pos] + 1;
      q.push(pos + 1);
    } else if (pos + 1 < MAX) {
      visited[pos + 1] = min(visited[pos + 1], visited[pos] + 1);
    }
    if (pos * 2 < MAX && visited[pos * 2] == 0) {
      visited[pos * 2] = visited[pos];
      q.push(pos * 2);
    } else if (pos * 2 < MAX) {
      visited[pos * 2] = min(visited[pos * 2], visited[pos]);
    }
  }
}

int main() {
  scanf("%d %d", &n, &k);
  bfs();
  printf("%d\n", visited[k] - 1);
}