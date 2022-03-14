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
  int l, r, a;
  scanf("%d %d %d", &l, &r, &a);
  while (a > 0) {
    if (l < r) {
      l++;
      a--;
    } else if (l > r) {
      r++;
      a--;
    } else if (l == r) {
      break;
    }
  }
  printf("%d\n", min(l, r) * 2 + (a / 2) * 2);
}