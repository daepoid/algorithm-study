#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  if (x > 0 && y > 0) {
    printf("1\n");
  } else if (x < 0 && y > 0) {
    printf("2\n");
  } else if (x < 0 && y < 0) {
    printf("3\n");
  } else {
    printf("4\n");
  }
}