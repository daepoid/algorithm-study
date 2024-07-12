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

long long int arr[31][31];
long long int dp(int w, int h) {
  if (arr[w][h] != 0) {
    return arr[w][h];
  }

  if (w == 0) {
    return 1;
  }
  arr[w][h] = dp(w - 1, h + 1);
  if (h > 0) {
    arr[w][h] += dp(w, h - 1);
  }
  return arr[w][h];
}

int main() {
  int n;
  while (true) {
    scanf("%d", &n);
    if (n == 0) {
      return 0;
    }
    printf("%lld\n", dp(n, 0));
  }
}