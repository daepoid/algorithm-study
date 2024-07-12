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
  double a, b, c, d;
  double max = 0;
  int cnt = 0;
  scanf("%lf %lf", &a, &b);
  scanf("%lf %lf", &c, &d);
  for (int i = 0; i < 4; i++) {
    double temp = a / c + b / d;
    double temp2 = b;
    b = a;
    a = c;
    c = d;
    d = temp2;
    if (temp > max) {
      max = temp;
      cnt = i;
    }
  }
  printf("%d\n", cnt);
}