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

struct x {
  int num;
};

bool operator>(x a, x b) {
  if (abs(a.num) == abs(b.num)) {
    return a.num > b.num;
  } else {
    return abs(a.num) > abs(b.num);
  }
}

int main() {
  int n, temp;
  scanf("%d", &n);
  priority_queue<x, vector<x>, greater<x>> pq;
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    if (temp == 0) {
      if (pq.empty()) {
        printf("0\n");
      } else {
        printf("%d\n", pq.top().num);
        pq.pop();
      }
    } else {
      x tempx;
      tempx.num = temp;
      pq.push(tempx);
    }
  }
}