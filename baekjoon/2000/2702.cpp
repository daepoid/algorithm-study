#include<iostream>
using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {

  int tc;
  scanf("%d", &tc);
  while (tc-- > 0) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", lcm(a, b), gcd(a, b));
  }
}