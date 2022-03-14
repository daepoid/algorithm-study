#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < 2 * n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i >= j && i <= n) {
        printf("*");
      } else if (2 * n >= i + j && i > n) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    for (int j = 1; j <= n; j++) {
      if (i + j > n && i <= n) {
        printf("*");
      } else if (n + j > i && i > n) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}