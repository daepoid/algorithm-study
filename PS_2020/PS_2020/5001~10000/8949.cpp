#include<iostream>
using namespace std;

int a, b;
int numa[7], numb[7];

int main() {  
  scanf("%d %d", &a, &b);
  int lena = 0, lenb = 0;
  for (int i = 6; a > 0 || b > 0; i--) {
    if (a > 0) {
      numa[i] = a % 10;
      a /= 10;
      lena++;
    }
    if (b > 0) {
      numb[i] = b % 10;
      b /= 10;
      lenb++;
    }
    numa[i] = numa[i] + numb[i];
  }
  if (lena < lenb) {
    lena = lenb;
  }
  for (int i = 7 - lena; i < 7; i++) {
    printf("%d", numa[i]);
  }
  printf("\n");
}