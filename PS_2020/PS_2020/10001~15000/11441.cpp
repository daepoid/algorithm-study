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

int main() {
  int sum[100001], n, temp;
  sum[0] = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    sum[i + 1] = sum[i] + temp;
  }
  int m, a, b;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", sum[b] - sum[a - 1]);
  }
}