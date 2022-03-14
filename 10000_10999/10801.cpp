#include<iostream>
using namespace std;

int a[10], b[10];
int main() {
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < 10; i++) {
    scanf("%d", &b[i]);
    if (a[i] > b[i]) {
      ans++;
    } else if (a[i] < b[i]) {
      ans--;
    }
  }
  if (ans > 0) {
    printf("A\n");
  } else if (ans < 0) {
    printf("B\n");
  } else {
    printf("D\n");
  }
}
