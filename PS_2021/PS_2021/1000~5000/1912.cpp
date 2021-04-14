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

long long int arr[100001];

int main() {
  long long int n, sum = 0, max_sum = -100000001;
  scanf("%lld", &n);
  for (long long int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  for (long long int i = 0; i < n; i++) {
    sum += arr[i];
    max_sum = max(max_sum, sum);
    if (sum < 0) {
      sum = 0;
    }
  }
  printf("%lld\n", max_sum);
}