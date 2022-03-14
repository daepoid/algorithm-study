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
  int t, k;
  scanf("%d", &t);
  while (t-- > 0) {
    double ans = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
      ans = (ans + 0.5) * 2;
    }
    printf("%.0lf\n", ans);
  }
}