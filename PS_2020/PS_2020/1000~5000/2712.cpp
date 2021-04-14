#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc-- > 0){
    double n;
    char str[3];
    scanf("%lf %s", &n, str);
    if(strcmp(str, "kg") == 0){
      n *= 2.2046;
      printf("%.4lf lb\n", n);
    } else if (strcmp(str, "l") == 0) {
      n *= 0.2642;
      printf("%.4lf g\n", n);
    } else if (strcmp(str, "lb") == 0) {
      n *= 0.4536;
      printf("%.4lf kg\n", n);
    } else if (strcmp(str, "g") == 0) {
      n *= 3.7854;
      printf("%.4lf l\n", n);
    }
  }
}