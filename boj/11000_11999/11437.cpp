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

vector<int> v[50001];
int parent_arr[50001], depth_arr[50001];

void dfs(int parent_node, int current_node) {
  depth_arr[parent_node] = current_node++;
  for (int nextNode : v[parent_node]) {
    if (!depth_arr[nextNode]) {
      parent_arr[nextNode] = parent_node;
      dfs(nextNode, current_node);
    }
  }
}

void bfs(int parent_node, int current_node) {
  queue<int> q;
  q.push(parent_node);
  while (!q.empty()) {
    int qs = q.size();
    while (qs--) {
      int currentNode = q.front();
      depth_arr[currentNode] = current_node;
      q.pop();
      for (int nextNode : v[currentNode]) {
        if (!depth_arr[nextNode]) {
          parent_arr[nextNode] = currentNode;
          q.push(nextNode);
        }
      }
    }
  }
}

int main() {
  int n, m, a, b;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }

  dfs(1, 1);
  bfs(1, 1);

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    if (depth_arr[a] < depth_arr[b]) {
      swap(a, b);
    }
    while (depth_arr[a] != depth_arr[b]) {
      a = parent_arr[a];
    }
    while (a != b) {
      a = parent_arr[a];
      b = parent_arr[b];
    }
    printf("%d\n", a);
  }
}