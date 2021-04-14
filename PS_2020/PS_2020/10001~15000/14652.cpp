#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  printf("%d %d\n", k / m, k % m);
}