#include<iostream>
using namespace std;

int main() {

  int tc;
  scanf("%d", &tc);
  while (tc-- > 0) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= m; i++) {
      if (i * 2 + m - i == n) {
        printf("%d %d\n", m - i, i);
        break;
      }
    }
  }
}