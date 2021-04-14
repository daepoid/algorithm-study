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
  int n, k, l, a[3];
  vector<int> arr;
  scanf("%d %d %d", &n, &k, &l);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    if (min(a[0], min(a[1], a[2])) >= l & a[0] + a[1] + a[2] >= k) {
      arr.push_back(a[0]);
      arr.push_back(a[1]);
      arr.push_back(a[2]);
    }
  }
  printf("%d\n", arr.size() / 3);
  for (int i = 0; i < arr.size(); i++) {
    if (i == arr.size() - 1) {
      printf("%d\n", arr[i]);
    } else {
      printf("%d ", arr[i]);
    }
  }
}