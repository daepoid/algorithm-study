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

vector<int> graph[1001];
bool visited[1001];
int n, m, a, b, cnt = 0;

void dfs(int idx) {
  visited[idx] = true;
  for (int i = 0; i < graph[idx].size(); i++) {
    if (!visited[graph[idx][i]]) {
      dfs(graph[idx][i]);
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 1; i < n + 1; i++) {
    if (!visited[i]) {
      dfs(i);
      cnt++;
    }
  }
  printf("%d\n", cnt);
}