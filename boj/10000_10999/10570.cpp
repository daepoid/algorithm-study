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

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  } else {
    return a.second < b.second;
  }
}

int main() {
  int n, s, temp;
  scanf("%d", &n);
  while (n-- > 0) {
    scanf("%d", &s);
    vector<pair<int, int>> v(1001); // (count, number)
    for (int i = 0; i < s; i++) {
      scanf("%d", &temp);
      v[temp].first++;
      v[temp].second = temp;
    }
    sort(v.begin(), v.end(), compare);
    printf("%d\n", v[0].second);
  }
}