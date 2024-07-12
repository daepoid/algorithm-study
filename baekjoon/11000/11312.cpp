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
  long long int a, b;
  scanf("%d", &t);
  while (t-- > 0) {
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", (a / b) * (a / b));
  }
}