#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int h, m, s, t;
  scanf("%d %d %d", &h, &m, &s);
  scanf("%d", &t);
  s = s + t;
  if (s >= 60) {
    m += s / 60;
    s = s % 60;
  }
  if (m >= 60) {
    h += m / 60;
    m = m % 60;
  }
  if (h >= 24) {
    h = h % 24;
  }
  printf("%d %d %d\n", h, m, s);
}