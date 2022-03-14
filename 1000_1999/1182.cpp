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

int n, s, cnt = 0, arr[22];

void dfs(int i, int sum) {
  if (i == n) {
    return;
  }
  if (sum + arr[i] == s) {
    cnt++;
  }
  dfs(i + 1, sum);
  dfs(i + 1, sum + arr[i]);
}

int main() {
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  dfs(0, 0);
  printf("%d\n", cnt);
}