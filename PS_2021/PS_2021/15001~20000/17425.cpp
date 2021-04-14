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
#define MAX 1000001
using namespace std;

vector<long long int> g(MAX);
vector<long long int> f(MAX, 1);

int main() {
  long long int tc, n, sum;
  scanf("%lld", &tc);
  for (long long int i = 2; i < MAX; i++) {
    for (long long int j = 1; i * j < MAX; j++) {
      f[i * j] += i;
    }
  }
  for (long long int i = 1; i < MAX; i++) {
    g[i] = g[i - 1] + f[i];
  }
  while (tc-- > 0) {
    scanf("%lld", &n);
    printf("%lld\n", g[n]);
  }
}