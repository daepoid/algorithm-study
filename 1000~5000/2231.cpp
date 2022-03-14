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
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int sum = i, m = i;
    while (m > 0) {
      sum += m % 10;
      m /= 10;
    }
    if (sum == n) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("0\n");
}