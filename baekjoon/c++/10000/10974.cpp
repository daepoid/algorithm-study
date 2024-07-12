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
  int n;
  int arr[8];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  do {
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        printf("%d\n", arr[i]);
      } else {
        printf("%d ", arr[i]);
      }
    }
  } while (next_permutation(arr, arr + n));
}