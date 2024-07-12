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
  int r, c, zr, zc;
  char str[51][51];
  scanf("%d %d %d %d", &r, &c, &zr, &zc);
  for (int i = 0; i < r; i++) {
    scanf("%s", str[i]);
  }
  for (int i = 0; i < r * zr; i++) {
    for (int j = 0; j < c * zc; j++) {
      printf("%c", str[i / zr][j / zc]);
    }
    printf("\n");
  }
}