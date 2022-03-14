#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  while (true) {
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    if (a == 0 && b == 0) {
      break;
    }
    printf("%lld\n", 2 * a - b);
  }
}