#include<iostream>
using namespace std;

int main() {

  int max = 0, sum = 0;
  for (int i = 0; i < 10; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    sum = sum - a + b;
    if (sum > max) {
      max = sum;
    }
  }
  printf("%d", max);
}