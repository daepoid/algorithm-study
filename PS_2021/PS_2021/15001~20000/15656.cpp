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
int list[9], arr[9];
bool visited[9];

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
    if ((cnt == 0) || (cnt > 0 && list[cnt - 1] <= arr[i - 1])) {
      list[cnt] = arr[i - 1];
      dfs(cnt + 1);
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  dfs(0);
}