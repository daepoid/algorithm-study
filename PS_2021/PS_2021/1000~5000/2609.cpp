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
  int n;
  while (b != 0) {
    n = a % b;
    a = b;
    b = n;
  }
  return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n%d\n", gcd(a, b), lcm(a, b));
}