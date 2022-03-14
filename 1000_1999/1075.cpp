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
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  a = (a / 100) * 100;
  for (int i = 0; i < 100; i++, a++) {
    if (a % b == 0) {
      printf("%02d\n", i);
      return 0;
    }
  }
}