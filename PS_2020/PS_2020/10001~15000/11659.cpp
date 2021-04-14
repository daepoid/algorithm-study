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
  int n, m, temp, a, b;
  long long int sum[100001];
  sum[0] = 0;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &temp);
    sum[i] = sum[i - 1] + temp;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    printf("%lld\n", sum[b] - sum[a - 1]);
  }
}