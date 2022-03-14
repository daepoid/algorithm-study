#include<iostream>
using namespace std;

int main() {
  int min = 0, man = 0, temp;
  for (int i = 0; i < 4; i++) {
    scanf("%d", &temp);
    min += temp;
  }
  for (int i = 0; i < 4; i++) {
    scanf("%d", &temp);
    man += temp;
  }
  printf("%d\n", man > min ? man : min);
}