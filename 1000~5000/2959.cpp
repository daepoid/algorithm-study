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
  int a[4];
  scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
  sort(a, a + 4);
  printf("%d\n", a[0] * a[2]);
}