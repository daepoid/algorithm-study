#include<iostream>
using namespace std;

int main() {

  int n;
  int a = 0, b = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int temp1, temp2;
    scanf("%d %d", &temp1, &temp2);
    if (temp1 > temp2) {
      a++;
    } else if (temp1 < temp2) {
      b++;
    }
  }
  printf("%d %d\n", a, b);
}