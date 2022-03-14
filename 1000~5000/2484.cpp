#include<iostream>
#include<algorithm>
using namespace std;

int main() {

  int n, max = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a[4], b[2];
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    sort(a, a + 4);
    int sum;
    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
      sum = 50000 + a[0] * 5000;
    } else if ((a[0] == a[1] && a[1] == a[2] && a[2] != a[3]) ||
               (a[0] != a[1] && a[1] == a[2] && a[2] == a[3])) {
      if (a[0] == a[1]) {
        sum = 10000 + a[0] * 1000;
      } else {
        sum = 10000 + a[1] * 1000;
      }
    } else if (a[0] == a[1] && a[2] == a[3] && a[1] != a[2]) {
      sum = 2000 + a[0] * 500 + a[2] * 500;
    } else if (a[0] == a[1] || a[1] == a[2] || a[2] == a[3]) {
      if (a[0] == a[1]) {
        sum = 1000 + a[0] * 100;
      } else if (a[1] == a[2]) {
        sum = 1000 + a[1] * 100;
      } else {
        sum = 1000 + a[2] * 100; 
      }
    } else {
      sum = a[3] * 100;
    }
    max = max > sum ? max : sum;
  }
  printf("%d\n", max);
}