#include <bits/stdc++.h>
using namespace std;

long long int arr[100001];

int main() {
  int n, low = 0, high = 0, min_len = 222222;
  long long int sum = 0, s;
  scanf("%lld %lld", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  while (true) {
    if (high == n && low == n) {
      break;
    }
    if (sum >= s) {
      sum -= arr[low++];
      min_len = min(min_len, high - low + 1);
    } else if (high == n && sum < s) {
      break;
    } else {
      sum += arr[high++];
    }
  }
  if (min_len == 222222) {
    min_len = 0;
  }
  printf("%d\n", min_len);
}