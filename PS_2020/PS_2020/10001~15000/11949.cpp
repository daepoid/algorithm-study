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
// NOTE: 무슨말인지 문제를 이해 못했는데 맞음
int main() {
  int n, m, temp;
  scanf("%d %d", &n, &m);
  vector<int> v;
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    v.push_back(temp);
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (v[j] % i > v[j + 1] % i) {
        swap(v[j], v[j + 1]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n", v[i]);
  }
}