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
  int t;
  scanf("%d", &t);
  while (t-- > 0) {
    int n;
    long long int sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      sum += i * (i + 1) * (i + 2) / 2;
    }
    printf("%lld\n", sum);
  }
}