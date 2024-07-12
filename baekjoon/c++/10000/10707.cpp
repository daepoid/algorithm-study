#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int a, b, c, d, p;
  int sum_a, sum_b;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
  sum_a = a * p;
  if(p > c){
    sum_b = b + d * (p - c);
  }else{
    sum_b = b;
  }
  printf("%d\n", sum_a < sum_b ? sum_a : sum_b);
}