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
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int a[3];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    sort(a, a + 3);
    if (a[0] == a[2]) {
      printf("Case #%d: equilateral\n", i + 1);
    } else if (a[0] + a[1] <= a[2]) {
      printf("Case #%d: invalid!\n", i + 1);
    } else if (a[0] == a[1] || a[1] == a[2]) {
      printf("Case #%d: isosceles\n", i + 1);
    } else if (a[0] != a[1] && a[1] != a[2]) {
      printf("Case #%d: scalene\n", i + 1);
    }
  }
}