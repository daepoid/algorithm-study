#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}