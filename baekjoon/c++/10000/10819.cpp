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
  int n, temp, sum = 0, max = 0;
  int arr[8];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  do {
    sum = 0;
    for (int i = 0; i < n - 1; i++) {
      sum += abs(arr[i] - arr[i + 1]);
    }
    if (sum > max) {
      max = sum;
    }
  } while (next_permutation(arr, arr + n));
  printf("%d\n", max);
}