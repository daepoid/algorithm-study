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

vector<int> arr[2001];
bool visited[2001], flag = false;
int n, m, a, b;

void dfs(int idx, int cnt) {
  if (cnt == 4) {
    printf("1\n");
    exit(0);
  }
  visited[idx] = true;
  for (int i = 0; i < arr[idx].size(); i++) {
    if (!visited[arr[idx][i]]) {
      dfs(arr[idx][i], cnt + 1);
    }
  }
  visited[idx] = false;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    dfs(i, 0);
  }
  printf("0\n");
}