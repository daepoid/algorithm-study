#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, t, c, p;
  scanf("%d %d %d %d", &n, &t, &c, &p);
  printf("%d\n", ((n - 1) / t) * c * p);
}