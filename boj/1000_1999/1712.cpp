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
  long long int a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  if (c < b || (c == b && a > 0)) {
    printf("-1\n");
    return 0;
  }
  c = c - b;
  printf("%lld\n", a / c + 1);
}