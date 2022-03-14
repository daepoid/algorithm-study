#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, t, temp, ans = 0;
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    t -= temp;
    if (t >= 0) {
      ans++;
    }
  }
  printf("%d\n", ans);
}