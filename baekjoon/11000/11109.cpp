#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  long long int t, d, n, s, p;
  scanf("%lld", &t);
  while (t-- > 0) {
    scanf("%lld %lld %lld %lld", &d, &n, &s, &p);
    if (d + n * p > n * s) {
      printf("do not parallelize\n");
    } else if (d + n * p == n * s) {
      printf("does not matter\n");
    } else {
      printf("parallelize\n");
    }
  }
}