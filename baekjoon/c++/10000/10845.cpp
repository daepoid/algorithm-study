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

queue<int> q;

int main() {
  int t, n;
  char str[30];
  scanf("%d", &t);
  while (t-- > 0) {
    scanf("%s", str);
    if (strcmp(str, "push") == 0) {
      scanf("%d", &n);
      q.push(n);
    } else if (strcmp(str, "pop") == 0) {
      printf("%d\n", q.empty() ? -1 : q.front());
      if (!q.empty()) {
        q.pop();
      }
    } else if (strcmp(str, "size") == 0) {
      printf("%d\n", q.empty() ? 0 : q.size());
    } else if (strcmp(str, "empty") == 0) {
      printf("%d\n", q.empty() ? 1 : 0);
    } else if (strcmp(str, "front") == 0) {
      printf("%d\n", q.empty() ? -1 : q.front());
    } else if (strcmp(str, "back") == 0) {
      printf("%d\n", q.empty() ? -1 : q.back());
    }
  }
}