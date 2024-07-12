#include<iostream>
using namespace std;

bool numbers[42];

int main() {

  int n, count = 0;
  for (int i = 0; i < 10; i++) {
    scanf("%d", &n);
    n %= 42;
    if (!numbers[n]) {
      numbers[n] = true;
      count++;
    }
  }
  printf("%d\n", count);
}