#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int l, a, b, c, d;
  scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
  int temp1, temp2;
  temp1 = a / c;
  if (a % c != 0) {
    temp1++;
  }
  temp2 = b / d;
  if(b % d != 0){
    temp2++;
  }
  printf("%d\n", temp1 > temp2 ? l - temp1 : l - temp2);
}