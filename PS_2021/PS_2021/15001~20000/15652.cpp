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

int m, n;
int list[9];
int visited[9];

void dfs(int cnt) {
  if (cnt == m) {
    for (int i = 0; i < m; i++) {
      if (i == m - 1) {
        printf("%d\n", list[i]);
      } else {
        printf("%d ", list[i]);
      }
    }
    return;
  }
  for (int i = 1; i < n + 1; i++) {
    if (cnt == 0) {
      memset(list, 0, sizeof(list));
      list[cnt] = i;
      dfs(cnt + 1);
    } else if (cnt > 0 && list[cnt - 1] <= i) {
      list[cnt] = i;
      dfs(cnt + 1);
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  dfs(0);
}