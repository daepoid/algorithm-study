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
  int n, now;
  double gg, gb, bg, bb;
  double good[101], bad[101];
  scanf("%d %d", &n, &now);
  scanf("%lf %lf %lf %lf", &gg, &gb, &bg, &bb);
  if (now == 0) {
    good[0] = gg;
    bad[0] = gb;
  } else {
    good[0] = bg;
    bad[0] = bb;
  }
  for (int i = 1; i < n; i++) {
    good[i] = good[i - 1] * gg + bad[i - 1] * bg;
    bad[i] = good[i - 1] * gb + bad[i - 1] * bb;
  }
  printf("%.0lf\n%.0lf\n", round(good[n - 1] * 1000), round(bad[n - 1] * 1000));
}