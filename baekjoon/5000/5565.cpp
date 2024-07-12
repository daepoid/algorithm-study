#include<iostream>
using namespace std;

int main() {
  int total;
  scanf("%d", &total);
  for (int i = 0; i < 9; i++) {
    int temp;
    scanf("%d", &temp);
    total -= temp;
  }
  printf("%d", total);
}