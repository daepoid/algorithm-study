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
  int a[2], b[2];
  scanf("%d %d", &a[0], &a[1]);
  scanf("%d %d", &b[0], &b[1]);
  while (a[1] > 0 && b[1] > 0) {
    a[1] -= b[0];
    b[1] -= a[0];
  }
  if (a[1] > 0 && b[1] <= 0) {
    printf("PLAYER A\n");
  } else if (a[1] <= 0 && b[1] > 0) {
    printf("PLAYER B\n");
  } else if (a[1] <= 0 && b[1] <= 0) {
    printf("DRAW\n");
  }
}