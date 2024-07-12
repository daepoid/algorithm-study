#include<iostream>
using namespace std;

int main() {
  int n, temp;
  scanf("%d", &n);
  scanf("%d", &temp);
  while (temp != 0) {
    if (temp % n == 0) {
      printf("%d is a multiple of %d.\n", temp, n);
    } else {
      printf("%d is NOT a multiple of %d.\n", temp, n);
    }
    scanf("%d", &temp);
  }
}