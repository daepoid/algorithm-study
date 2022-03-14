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
bool a[100000001];

int main() {
  int x, y, temp, cnt = 0, max = 0;
  scanf("%d %d", &x, &y);
  for (int i = 0; i < x + y; i++) {
    scanf("%d", &temp);
    if (a[temp]) {
      a[temp] = false;
    } else {
      a[temp] = true;
    }
    if (max < temp) {
      max = temp;
    }
  }
  for (int i = 1; i < max + 1; i++) {
    if (a[i]) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}