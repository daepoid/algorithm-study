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
  int n, l, temp;
  vector<int> pos;
  scanf("%d %d", &n, &l);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    pos.push_back(temp);
  }
  sort(pos.begin(), pos.end());
  for (int i = 0; i < pos.size(); i++) {
    if (l >= pos[i]) {
      l++;
    }
  }
  printf("%d\n", l);
}