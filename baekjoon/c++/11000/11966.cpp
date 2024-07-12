#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  long long int x;
  scanf("%lld", &x);
  while (x != 1) {
    if (x % 2 == 1) {
      break;
    } else {
      x /= 2;
    }
  }
  if (x == 1) {
    printf("1\n");
  } else {
    printf("0\n");
  }
}