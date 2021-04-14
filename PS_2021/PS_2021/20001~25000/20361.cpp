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
  int n, x, k;
  int a, b;
  vector<bool> cups;
  scanf("%d %d %d", &n, &x, &k);
  for (int i = 0; i < n; i++) {
    if (i == x - 1) {
      cups.push_back(true);
    } else {
      cups.push_back(false);
    }
  }
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &a, &b);
    swap(cups[a - 1], cups[b - 1]);
  }
  for (int i = 0; i < cups.size(); i++) {
    if (cups[i]) {
      printf("%d\n", i + 1);
    }
  }
}