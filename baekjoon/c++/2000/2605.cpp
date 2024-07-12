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
  int n, card;
  deque<int> deq, temp;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &card);
    for (int j = 0; j < card; j++) {
      temp.push_front(deq.back());
      deq.pop_back();
    }
    deq.push_back(i);
    while (!temp.empty()) {
      deq.push_back((temp.front()));
      temp.pop_front();
    }
  }
  while (!deq.empty()) {
    if (deq.size() == 1) {
      printf("%d\n", deq.front());
    } else {
      printf("%d ", deq.front());
    }
    deq.pop_front();
  }
}