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
  int a[3];
  scanf("%d %d %d", &a[0], &a[1], &a[2]);
  sort(a, a + 3);
  if (a[1] - a[0] == a[2] - a[1]) {
    printf("%d\n", a[2] + a[1] - a[0]);
  } else if (a[1] - a[0] == 2 * (a[2] - a[1])) {
    printf("%d\n", a[0] + a[2] - a[1]);
  } else if (2 * (a[1] - a[0]) == (a[2] - a[1])) {
    printf("%d\n", a[1] + a[1] - a[0]);
  }
}