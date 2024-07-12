#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int a[3], b[3], c[3];
  scanf("%d %d %d", &a[0], &a[1], &a[2]);
  scanf("%d %d %d", &c[0], &c[1], &c[2]);
  printf("%d %d %d\n", c[0] - a[2], c[1] / a[1], c[2] - a[0]);
}