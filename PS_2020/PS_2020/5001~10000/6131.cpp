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
  int n, cnt = 0;
  scanf("%d", &n);
  for (int b = 1; b <= 500; b++) {
    for (int a = b; a <= 500; a++) {
      if (b * b + n == a * a) {
        cnt++;
      } else if (b * b + n < a * a) {
        break;
      }
    }
  }
  printf("%d\n", cnt);
}