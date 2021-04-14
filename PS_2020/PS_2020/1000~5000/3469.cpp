#include<iostream>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc-- > 0) {
    int n;
    scanf("%d", &n);
    int i = 0;
    for (i = 0; n > 0; i++, n /= 2) {
      if (n % 2 == 1) {
        printf("%d", i);
        if (n / 2 != 0) {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
}