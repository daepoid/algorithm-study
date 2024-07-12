#include <algorithm>
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
  while (true) {
    int a[3];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    if (a[0] == 0 && a[1] == 0 && a[2] == 0) {
      break;
    }
    sort(a, a + 3);
    if (a[0] == a[1] && a[0] == a[2]) {
      printf("Equilateral\n");
    } else if (a[0] + a[1] <= a[2]) {
      printf("Invalid\n");
    } else if (a[0] == a[1] || a[1] == a[2]) {
      printf("Isosceles\n");
    } else if (a[0] != a[1] && a[1] != a[2]) {
      printf("Scalene\n");
    }
  }
}