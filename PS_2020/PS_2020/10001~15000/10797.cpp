#include<iostream>
using namespace std;

int main() {

  int n, count = 0;
  scanf("%d", &n);

  for (int i = 0; i < 5; i++) {
    int temp;
    scanf("%d", &temp);
    if (temp == n) {
      count++;
    }
  }
  printf("%d\n", count);
}