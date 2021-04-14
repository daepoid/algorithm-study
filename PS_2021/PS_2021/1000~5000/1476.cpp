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
  int e, s, m;
  scanf("%d %d %d", &e, &s, &m);
  e %= 15;
  s %= 28;
  m %= 19;
  for (int i = 1; i < 7981; i++) {
    if (i % 15 == e && i % 28 == s && i % 19 == m) {
      printf("%d\n", i);
      break;
    }
  }
}