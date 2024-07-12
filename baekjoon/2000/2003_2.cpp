#include <bits/stdc++.h>
using namespace std;

long long int arr[10001];

int main() {
  int n, m;
  int low = 0, high = 0, cnt = 0;
  long long int sum = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  while (true) {
    if (high == n) {
      break;
    }
    if (sum >= m) {
      sum -= arr[low++];
    } else {
      sum += arr[high++];
    }

    if (sum == m) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}