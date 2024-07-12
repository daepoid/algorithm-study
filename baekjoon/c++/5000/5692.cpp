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

int fac[6] = {1, 1, 2, 6, 24, 120};

int main() {
  int n;
  while (true) {
    int sum = 0;
    scanf("%d", &n);
    if (n == 0) {
      return 0;
    }
    for (int i = 1; n > 0; i++) {
      sum += (n % 10) * fac[i];
      n /= 10;
    }
    printf("%d\n", sum);
  }
}