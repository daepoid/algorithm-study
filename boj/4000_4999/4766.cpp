#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  double a, b = 1000;

  scanf("%lf", &a);
  while(b != 999){
    if(b != 1000){
      printf("%.2lf\n", b - a);
      a = b;
    }
    scanf("%lf", &b);   
  }
}