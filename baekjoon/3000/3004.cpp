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
  int n, sum = 0;
  scanf("%d", &n);
  for (int i = 1; true; i++) {
    sum += (i * i + (i - 1) * (i - 1));
    if (sum > n) {
      printf("%d\n", i - 1);
      break;
    }
  }
}