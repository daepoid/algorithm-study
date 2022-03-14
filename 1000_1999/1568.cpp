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
  int n, j = 0;
  scanf("%d", &n);
  while (n != 0) {
    for (int i = 1; i <= n; i++) {
      if (i * (i + 1) / 2 > n) {
        n -= (i * (i - 1) / 2);
        j += i - 1;
        break;
      } else if (i * (i + 1) / 2 == n) {
        n -= (i * (i + 1) / 2);
        j += i;
      }
    }
  }
  printf("%d\n", j);
}