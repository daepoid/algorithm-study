#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  long long int a, b, c;
  int n;
  scanf("%d", &n);
  if (n == 2) {
    c = 0;
    scanf("%lld %lld", &a, &b);
  } else {
    scanf("%lld %lld %lld", &a, &b, &c);
  }
  for (long long int i = 1; i <= a; i++) {
    if (a % i == 0 && b % i == 0 && c % i == 0) {
      printf("%d\n", i);
    }
  }
}