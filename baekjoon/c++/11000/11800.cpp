#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

char str[6][10] = {"Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a[2];
    scanf("%d %d", &a[0], &a[1]);
    sort(a, a + 2);
    printf("Case %d: ", i + 1);
    if (a[0] == a[1]) {
      switch (a[0]) {
      case 1:
        printf("Habb Yakk\n");
        break;
      case 2:
        printf("Dobara\n");
        break;
      case 3:
        printf("Dousa\n");
        break;
      case 4:
        printf("Dorgy\n");
        break;
      case 5:
        printf("Dabash\n");
        break;
      case 6:
        printf("Dosh\n");
        break;
      default:
        break;
      }
    } else if (a[0] == 5 && a[1] == 6) {
      printf("Sheesh Beesh\n");
    } else {
      printf("%s %s\n", str[a[1] - 1], str[a[0] - 1]);
    }
  }
}