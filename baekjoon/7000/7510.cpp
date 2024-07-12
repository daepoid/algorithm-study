#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, a[3];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    sort(a, a + 3);
    if (a[2] * a[2] == a[0] * a[0] + a[1] * a[1]) {
      printf("Scenario #%d:\nyes\n", i + 1);
    } else {
      printf("Scenario #%d:\nno\n", i + 1);
    }
    printf("\n");
  }
}