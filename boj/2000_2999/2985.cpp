#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  if (a + b == c) {
    printf("%d+%d=%d\n", a, b, c);
  } else if (a - b == c) {
    printf("%d-%d=%d\n", a, b, c);
  } else if (a * b == c) {
    printf("%d*%d=%d\n", a, b, c);
  } else if (a / b == c) {
    printf("%d/%d=%d\n", a, b, c);
  } else if (a == b + c) {
    printf("%d=%d+%d\n", a, b, c);
  } else if (a == b - c) {
    printf("%d=%d-%d\n", a, b, c);
  } else if (a == b * c) {
    printf("%d=%d*%d\n", a, b, c);
  } else if (a == b / c) {
    printf("%d=%d/%d\n", a, b, c);
  }
}
