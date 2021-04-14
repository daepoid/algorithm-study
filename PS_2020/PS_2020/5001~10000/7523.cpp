#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  long long int n, m, ans;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%lld %lld", &n, &m);
    printf("Scenario #%d:\n%lld\n\n", i + 1, (m + n) * (m - n + 1) / 2);
  }
}