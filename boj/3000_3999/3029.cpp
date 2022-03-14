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
  int ah, am, as;
  int bh, bm, bs;
  scanf("%d:%d:%d", &ah, &am, &as);
  scanf("%d:%d:%d", &bh, &bm, &bs);
  if (as > bs) {
    bs += 60;
    bm--;
  }
  if (am > bm) {
    bm += 60;
    bh--;
  }
  if (ah > bh) {
    bh += 24;
  }
  if (ah == bh && am == bm && as == bs) {
    bh += 24;
  }
  printf("%02d:%02d:%02d\n", bh - ah, bm - am, bs - as);
}