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

int n, temp, arr[100], op[4];
int max_val = -2100000000;
int min_val = 2100000000;

void dfs(int plus, int minus, int mult, int divide, int sum, int idx) {
  if (idx == n) {
    max_val = max(max_val, sum);
    min_val = min(min_val, sum);
    return;
  }
  if (plus < op[0]) {
    dfs(plus + 1, minus, mult, divide, sum + arr[idx], idx + 1);
  }
  if (minus < op[1]) {
    dfs(plus, minus + 1, mult, divide, sum - arr[idx], idx + 1);
  }
  if (mult < op[2]) {
    dfs(plus, minus, mult + 1, divide, sum * arr[idx], idx + 1);
  }
  if (divide < op[3]) {
    dfs(plus, minus, mult, divide + 1, sum / arr[idx], idx + 1);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < 4; i++) {
    scanf("%d", &op[i]);
  }
  dfs(0, 0, 0, 0, arr[0], 1);
  printf("%d\n%d\n", max_val, min_val);
}