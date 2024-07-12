#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int a[4];
  int b[2];
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  for (int i = 0; i < 2; i++) {
    scanf("%d", &b[i]);
    sum += b[i];
  }
  sort(a, a + 4);
  sort(b, b + 2);
  printf("%d\n", sum - a[0] - b[0]);
}