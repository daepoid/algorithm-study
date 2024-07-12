#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n + i; j++) {
      if (j == n - i - 1 || j == n + i - 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}