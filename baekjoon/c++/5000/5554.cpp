#include <iostream>
using namespace std;

int main() {
  int n;
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    scanf("%d", &n);
    sum += n;
  }
  printf("%d\n%d", sum / 60, sum % 60);
}