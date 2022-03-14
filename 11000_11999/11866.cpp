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
  int n, k;
  queue<int> q;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    q.push(i + 1);
  }
  printf("<");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k - 1; j++) {
      int temp = q.front();
      q.push(temp);
      q.pop();
    }
    if (i == n - 1) {
      printf("%d>\n", q.front());
      q.pop();
    } else {
      printf("%d, ", q.front());
      q.pop();
    }
  }
}