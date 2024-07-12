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
using namespace std;

vector<int> arr[1001];
int n, m, v, a, b;
bool visited[1001];
bool visited2[1001];

void dfs(int idx) {
  printf("%d ", idx);
  visited[idx] = true;
  for (int i = 0; i < arr[idx].size(); i++) {
    if (!visited[arr[idx][i]]) {
      dfs(arr[idx][i]);
    }
  }
}
void bfs(int idx) {
  queue<int> q;
  q.push(idx);
  visited2[idx] = true;
  while (!q.empty()) {
    idx = q.front();
    printf("%d ", q.front());
    q.pop();
    for (int i = 0; i < arr[idx].size(); i++) {
      if (!visited2[arr[idx][i]]) {
        q.push(arr[idx][i]);
        visited2[arr[idx][i]] = true;
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &v);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  dfs(v);
  printf("\n");
  bfs(v);
}