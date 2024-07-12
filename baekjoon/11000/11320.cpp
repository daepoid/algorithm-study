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

int main() {
  int t, a, b;
  scanf("%d", &t);
  while (t-- > 0) {
    scanf("%d %d", &a, &b);
    printf("%d\n", (a / b) * (a / b));
  }
}