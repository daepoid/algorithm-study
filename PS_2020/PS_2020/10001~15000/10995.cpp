#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      if ((i + j) % 2 == 1) {
        printf(" ");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
}