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
  int a, b, c, d;
  while (true) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a == 0 && b == 0 && c == 0 && d == 0) {
      break;
    }
    int cnt = 0;
    while (true) {
      if (a == b && b == c && c == d) {
        break;
      }
      int new_a = abs(b - a);
      int new_b = abs(c - b);
      int new_c = abs(d - c);
      int new_d = abs(a - d);
      a = new_a;
      b = new_b;
      c = new_c;
      d = new_d;
      cnt++;
    }
    printf("%d\n", cnt);
  }
}