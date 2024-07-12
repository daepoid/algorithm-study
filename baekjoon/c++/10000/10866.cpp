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

deque<int> deq;

int main() {
  int t, n;
  char str[20];
  scanf("%d", &t);
  while (t-- > 0) {
    scanf("%s", str);
    if (strcmp(str, "push_front") == 0) {
      scanf("%d", &n);
      deq.push_front(n);
    } else if (strcmp(str, "push_back") == 0) {
      scanf("%d", &n);
      deq.push_back(n);
    } else if (strcmp(str, "pop_front") == 0) {
      printf("%d\n", deq.empty() ? -1 : deq.front());
      if (!deq.empty()) {
        deq.pop_front();
      }
    } else if (strcmp(str, "pop_back") == 0) {
      printf("%d\n", deq.empty() ? -1 : deq.back());
      if (!deq.empty()) {
        deq.pop_back();
      }
    } else if (strcmp(str, "size") == 0) {
      printf("%d\n", deq.empty() ? 0 : deq.size());
    } else if (strcmp(str, "empty") == 0) {
      printf("%d\n", deq.empty() ? 1 : 0);
    } else if (strcmp(str, "front") == 0) {
      printf("%d\n", deq.empty() ? -1 : deq.front());
    } else if (strcmp(str, "back") == 0) {
      printf("%d\n", deq.empty() ? -1 : deq.back());
    }
  }
}