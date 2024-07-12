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

deque<int> deq[1001];

void left_check(int idx, int direction) {}
void right_check(int idx, int direction) {}

void roll(int idx, int direction) {
  if (direction == 1) {
    left_check(idx, direction * (-1));
    right_check(idx, direction * (-1));
    
  } else if (direction == -1) {
    left_check(idx, direction * (-1));
    right_check(idx, direction * (-1));
  }
}

int main() {
  int t, k, cnt = 0;
  char str[10];
  for (int i = 0; i < t; i++) {
    scanf("%s", str);
    for (int j = 0; j < 8; j++) {
      deq[i].push_back(str[j] - '0');
    }
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    roll(a - 1, b);
  }
  for (int i = 0; i < t; i++) {
    if (deq[i].front() == 1) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}