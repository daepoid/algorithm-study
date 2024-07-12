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
  int n;
  while (b != 0) {
    n = a % b;
    a = b;
    b = n;
  }
  return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  int n, M, N, x, y;
  bool flag;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &M, &N, &x, &y);
    flag = false;
    while (x <= M * N && y <= M * N) {
      if (x == y) {
        flag = true;
        break;
      }
      if (x < y) {
        x += M;
      } else {
        y += N;
      }
    }
    if (flag) {
      printf("%d\n", x);
    } else {
      printf("-1\n");
    }
  }
}