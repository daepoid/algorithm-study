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

int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main() {
  int a[5], min = -1;
  for (int i = 0; i < 5; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + 5);
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 4; j++) {
      for (int k = j + 1; k < 5; k++) {
        int temp = lcm(lcm(a[i], a[j]), a[k]);
        if (temp < min || min == -1) {
          min = temp;
        }
      }
    }
  }
  printf("%d\n", min);
}