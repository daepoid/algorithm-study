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
  int n, m;
  vector<int> v;
  vector<bool> comb;

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    v.push_back(i + 1);
  }
  for (int i = 0; i < m; i++) {
    comb.push_back(true);
  }
  for (int i = 0; i < n - m; i++) {
    comb.push_back(false);
  }

  do {
    for (int i = 0; i < n; i++) {
      if (comb[i]) {
        printf("%d ", v[i]);
      }
    }
    printf("\n");

  } while (prev_permutation(comb.begin(), comb.end()));
}