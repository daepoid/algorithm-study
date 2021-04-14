#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int tc;

  scanf("%d", &tc);
  while(tc-- > 0){
    int a, b, c, d, e;
    double sum = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    sum = a * 350.34 + b * 230.90 + c * 190.55 + d * 125.30 + e * 180.90;
    printf("$%.2lf\n", sum);
  }
}