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

int arr[11];

int main() {
  int tc, n;
  scanf("%d", &tc);
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;
  for (int i = 4; i < 11; i++) {
    arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
  }
  while (tc-- > 0) {
    scanf("%d", &n);
    printf("%d\n", arr[n]);
  }
}