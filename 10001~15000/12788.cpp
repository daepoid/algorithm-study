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
  int n, m, k, i;
  int arr[1000], sum = 0;
  scanf("%d", &n);
  scanf("%d %d", &m, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n, greater<int>());
  for (i = 0; i < n; i++) {
    sum += arr[i];
    if (sum >= m * k) {
      printf("%d\n", i + 1);
      return 0;
    }
  }
  printf("STRESS\n");
}