#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, m, temp;
  set<int> a;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    a.insert(temp);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &temp);
    auto it = a.find(temp);
    if (it != a.end()) {
      a.erase(it);
    }
  }
  printf("%d\n", a.size());
  for (auto num : a) {
    printf("%d ", num);
  }
  printf("\n");
}