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
#define MAX 2000001
using namespace std;

int n, arr[22];
bool check[MAX];

void dfs(int i, int sum) {
  if (i == n) {
    check[sum] = true;
    return;
  }
  dfs(i + 1, sum);
  dfs(i + 1, sum + arr[i]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  dfs(0, 0);
  for (int i = 1; i < MAX; i++) {
    if (!check[i]) {
      printf("%d\n", i);
      break;
    }
  }
}