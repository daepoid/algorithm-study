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
  long long int sum;
  scanf("%lld", &n);
  sum = 3 * n * (n + 1) / 2 + n + 1;
  printf("%lld\n", sum % 45678);
}