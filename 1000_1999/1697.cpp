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

int visited[MAX], n, k;
queue<int> q;

void bfs() {
  q.push(n);
  visited[n] = 1;
  while (!q.empty()) {
    int pos = q.front();
    q.pop();
    if (pos == k) {
      return;
    }
    if (0 <= pos - 1 && visited[pos - 1] == 0) {
      visited[pos - 1] = visited[pos] + 1;
      q.push(pos - 1);
    }
    if (pos + 1 < MAX && visited[pos + 1] == 0) {
      visited[pos + 1] = visited[pos] + 1;
      q.push(pos + 1);
    }
    if (2 * pos < MAX && visited[2 * pos] == 0) {
      visited[2 * pos] = visited[pos] + 1;
      q.push(2 * pos);
    }
  }
}

int main() {
  scanf("%d %d", &n, &k);
  bfs();
  printf("%d\n", visited[k] - 1);
}