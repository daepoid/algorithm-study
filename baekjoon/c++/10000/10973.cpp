#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, chk = 0;
  int arr[10000], temp[10000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    temp[i] = arr[i];
  }
  sort(temp, temp + n, greater<int>());
  prev_permutation(arr, arr + n);
  for (int i = 0; i < n; i++) {
    if (arr[i] == temp[i]) {
      chk++;
    } else {
      break;
    }
  }
  if (chk == n) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      printf("%d\n", arr[i]);
    } else {
      printf("%d ", arr[i]);
    }
  }
}