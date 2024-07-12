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

// NOTE: 규칙 이해하기

int main() {
  long long int n, temp, sum = 0;
  scanf("%lld", &n);
  for (int i = 1; i < n + 1; i++) {
    sum += i * (n / i);
  }
  printf("%lld\n", sum);
}