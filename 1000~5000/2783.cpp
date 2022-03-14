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
  double x, y;
  int n;
  scanf("%lf %lf", &x, &y);
  scanf("%d", &n);
  double min = x / y;
  while (n-- > 0) {
    double a, b;
    scanf("%lf %lf", &a, &b);
    if (min > a / b) {
      min = a / b;
    }
  }
  printf("%0.2lf", min * 1000);
}