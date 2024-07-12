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
  int n, start = 0, end = 0, temp, max_val = 0;
  scanf("%d", &n);
  scanf("%d", &start);
  for (int i = 1; i < n; i++) {
    scanf("%d", &temp);
    if (end < temp) {
      end = temp;
      if (end < start) {
        start = end;
      }
    } else if (end >= temp && start < end) {
      start = temp;
      end = 0;
    } else if (start >= end) {
      start = end;
    }
    max_val = max_val > (end - start) ? max_val : (end - start);
  }
  printf("%d\n", max_val);
}