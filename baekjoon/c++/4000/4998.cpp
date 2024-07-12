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
  double n, b, m;
  while (scanf("%lf %lf %lf", &n, &b, &m) != EOF) {
    b /= 100;
    for (int i = 0; true; i++) {
      if (n * pow((1 + b), i) >= m) {
        printf("%d\n", i);
        break;
      }
    }
  }
}