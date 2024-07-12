#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int tc, temp;
  scanf("%d", &tc);
  while (tc-- > 0) {
    int sum = 0;
    int min = 100;
    for (int i = 0; i < 7; i++) {
      scanf("%d", &temp);
      if (temp % 2 == 0) {
        sum += temp;
        if (temp < min) {
          min = temp;
        }
      }
    }
    printf("%d %d\n", sum, min);
  }
}