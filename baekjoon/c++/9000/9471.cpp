#include <bits/stdc++.h>
using namespace std;

int fib[1000011];

int main() {
  int p, n, m, i;
  fib[0] = 0;
  fib[1] = 1;
  scanf("%d", &p);
  while (p-- > 0) {
    i = 2;
    scanf("%d %d", &n, &m);
    while (true) {
      fib[i] = (fib[i - 1] + fib[i - 2]) % m;
      if (fib[i - 1] == 0 && fib[i] == 1) {
        break;
      }
      i++;
    }
    printf("%d %d\n", n, i - 1);
  }
}