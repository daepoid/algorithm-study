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

int n, k;
queue<int> q;
int visited[MAX], before[MAX];
vector<int> ans;

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
      before[pos - 1] = pos;
      q.push(pos - 1);
    }
    if (pos + 1 < MAX && visited[pos + 1] == 0) {
      visited[pos + 1] = visited[pos] + 1;
      before[pos + 1] = pos;
      q.push(pos + 1);
    }
    if (pos * 2 < MAX && visited[pos * 2] == 0) {
      visited[pos * 2] = visited[pos] + 1;
      before[pos * 2] = pos;
      q.push(pos * 2);
    }
  }
}

int main() {
  int temp;
  scanf("%d %d", &n, &k);
  bfs();
  printf("%d\n", visited[k] - 1);
  ans.push_back(k);
  temp = k;
  for (int i = 0; i < visited[k] - 1; i++) {
    ans.push_back(before[temp]);
    temp = before[temp];
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    if (i == 0) {
      printf("%d\n", ans[i]);
    } else {
      printf("%d ", ans[i]);
    }
  }
}