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
  int t;
  vector<pair<int, pair<int, int>>> v;
  scanf("%d", &t);
  while (t-- > 0) {
    int c, n, p;
    scanf("%d %d %d", &c, &n, &p);
    v.push_back(pair<int, pair<int, int>>(p, make_pair(c, n)));
  }
  sort(v.begin(), v.end());
  printf("%d %d\n", v[v.size() - 1].second.first,
         v[v.size() - 1].second.second);
  printf("%d %d\n", v[v.size() - 2].second.first,
         v[v.size() - 2].second.second);

  if (v[v.size() - 1].second.first == v[v.size() - 2].second.first) {
    for (int i = v.size() - 3; i >= 0; i--) {
      if (v[v.size() - 1].second.first != v[i].second.first) {
        printf("%d %d\n", v[i].second.first, v[i].second.second);
        return 0;
      }
    }
  } else {
    printf("%d %d\n", v[v.size() - 3].second.first,
           v[v.size() - 3].second.second);
    return 0;
  }
}