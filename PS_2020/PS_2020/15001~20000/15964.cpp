#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  long long int a, b;
  scanf("%lld %lld", &a, &b);
  printf("%lld\n", (a + b) * (a - b));
}