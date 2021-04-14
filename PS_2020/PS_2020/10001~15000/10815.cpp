#include<iostream>
#include<cmath>
using namespace std;

int main() {
  int a, b, sqrt_a;
  long long int sum = 0, min = 0;
  scanf("%d %d", &a, &b);

  if (a > b) {
    int temp = b;
    a = b;
    b = temp;
  }
  sqrt_a = sqrt(a);
  if (sqrt_a * sqrt_a != a) {
    sqrt_a++;
  }
  min = sqrt_a * sqrt_a;
  for (int i = sqrt_a; i * i <= b; i++) {
    sum += i * i;
  }
  if (sum == 0) {
    printf("-1");
  } else {
    printf("%lld\n%lld", sum, min);  
  }
}