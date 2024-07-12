#include<iostream>
using namespace std;

int main() {

  int x[50], y[50], n, cnt;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  for (int i = 0; i < n; i++) {
    cnt = 1;
    for (int j = 0; j < n; j++) {
      if (x[i] < x[j] && y[i] < y[j]) {
        cnt++;
      } 
    }
    printf("%d", cnt);
    if (i + 1 < n) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
}