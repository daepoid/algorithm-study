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
  long long int n;
  long long int sum = 0;
  scanf("%lld", &n);
  printf("%lld\n", (n - 1) * n / 2 * (n + 1));
}