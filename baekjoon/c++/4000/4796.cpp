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
  int l, p, v;
  int ans = 0;
  for (int i = 0; true; i++) {
    ans = 0;
    scanf("%d %d %d", &l, &p, &v);
    if (l == 0 && p == 0 && v == 0) {
      return 0;
    }
    while (true) {
      if (v >= p) {
        ans += l;
        v -= p;
      }
      if (v < p) {
        if (v <= l) {
          ans += v;
          break;
        } else if (v > l) {
          ans += l;
          break;
        }
      }
    }
    printf("Case %d: %d\n", i + 1, ans);
  }
}