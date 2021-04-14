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
  int n, before = -1000000;
  while (scanf("%d", &n) != EOF) {
    if (n < before) {
      printf("Bad\n");
      return 0;
    }
    before = n;
  }
  printf("Good\n");
}