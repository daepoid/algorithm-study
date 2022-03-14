#include<iostream>
using namespace std;

int main() {
  int burger = 2000, drink = 2000;
  int temp;
  for (int i = 0; i < 3; i++) {
    scanf("%d", &temp);
    if (temp < burger) {
      burger = temp;
    }
  }
  for (int i = 0; i < 2; i++) {
    scanf("%d", &temp);
    if (temp < drink) {
      drink = temp;
    }
  }
  printf("%d\n", burger + drink - 50);
}