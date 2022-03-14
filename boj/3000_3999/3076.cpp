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
  int r, c, a, b;
  scanf("%d %d", &r, &c);
  scanf("%d %d", &a, &b);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < a; j++) {
      for (int k = 0; k < c; k++) {
        for (int l = 0; l < b; l++) {
          if ((i + k) % 2 == 0) {
            printf("X");
          } else {
            printf(".");
          }
        }
      }
      printf("\n");
    }
  }
}