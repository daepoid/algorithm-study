#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  n--;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 2 * n + 1; j++) {
      if (j < i) {
        printf(" ");
      } else if (2 * n - i < j) {
        
      }else {
        printf("*");
      }
    }
    printf("\n");
  }
}