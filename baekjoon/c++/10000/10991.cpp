#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  n--;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 2 * n + 1; j++) {
      if (j < n - i) {
        printf(" ");
      } else if (n + i < j) {
      } else {
        if (n % 2 == 0) {
          if ((i + j) % 2 == 0) {
            printf("*");
          } else {
            printf(" ");
          }
        } else {
          if ((i + j) % 2 == 0) {
            printf(" ");
          } else {
            printf("*");
          }
        }
      }
    }
    printf("\n");
  }
}