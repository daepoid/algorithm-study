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

long long int arr[10001];

int main() {
  long long int n, m, sum = 0, cnt = 0, low = 0, high = 0;
  scanf("%lld %lld", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  while (1) {
    if (sum >= m) {
      sum -= arr[low++];
    } else if (high == n) {
      break;
    } else {
      sum += arr[high++];
    }
    if (sum == m) {
      cnt++;
    }
  }
  printf("%lld\n", cnt);
}