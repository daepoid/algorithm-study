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

long long int gcd(long long int a, long long int b) {
  long long int n;
  if (a < b) {
    swap(a, b);
  }
  while (b != 0) {
    n = a % b;
    a = b;
    b = n;
  }
  return a;
}

int main() {
  long long int a, b, c, d;
  scanf("%lld %lld", &a, &b);
  scanf("%lld %lld", &c, &d);
  long long int temp = b;
  b = b * d;
  a = a * d;
  c = c * temp;
  printf("%lld %lld\n", (a + c) / gcd(a + c, b), b / gcd(a + c, b));
}