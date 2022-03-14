#include<iostream>
using namespace std;

int tc;

int main() {

  scanf("%d", &tc);
  while (tc-- > 0) {
    int n;
    int max = 0, min = 100, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int temp;
      scanf("%d", &temp);
      if (temp > max) {
        max = temp;
      }
      if (temp < min) {
        min = temp;
      }
      sum += temp;
    }
    sum /= n;
    printf("%d\n", (max - sum) * 2 + (sum - min) * 2);
  }
}