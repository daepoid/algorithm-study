#include<iostream>
using namespace std;

int main() {
  int m, d;
  scanf("%d %d", &m, &d);
  if (m > 2) {
    printf("After\n");
  } else if (m < 2) {
    printf("Before\n");
  } else {
    if (d < 18) {
      printf("Before\n");
    } else if (d > 18) {
      printf("After\n");
    } else {
      printf("Special\n");
    }
  }
}