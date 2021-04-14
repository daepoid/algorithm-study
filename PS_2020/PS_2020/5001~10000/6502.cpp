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
  double a, b, c;
  for (int i = 1; true; i++) {
    scanf("%lf", &a);
    if (a == 0) {
      return 0;
    }
    scanf("%lf %lf", &b, &c);
    if (2 * a > b && 2 * a > c && b * b + c * c <= 4 * a * a) {
      printf("Pizza %d fits on the table.\n", i);
    } else {
      printf("Pizza %d does not fit on the table.\n", i);
    }
  }
}