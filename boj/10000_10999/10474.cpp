#include<iostream>
using namespace std;

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  while (a != 0 && b != 0) {
    printf("%d %d / %d\n", a / b, a % b, b);
    scanf("%d %d", &a, &b);
  }
}