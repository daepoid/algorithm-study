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

int gcd(int a, int b) {
  int temp;
  if (a < b) {
    swap(a, b);
  }
  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int main() {
  int x, y, z;
  scanf("%d %d", &x, &y);

  y = y / x;
  for (int i = 1; i * i <= y; i++) {
    if (y % i == 0 && gcd(i, y / i) == 1) {
      z = i;
    }
  }
  printf("%d %d\n", x * z, x * (y / z));
}
