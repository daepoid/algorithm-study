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

string num[10] = {"zero", "one", "two",   "three", "four",
                  "five", "six", "seven", "eight", "nine"};

int main() {
  int m, n;
  vector<pair<string, int>> v;
  scanf("%d %d", &m, &n);
  for (int i = m; i <= n; i++) {
    if (i < 10) {
      v.push_back(pair<string, int>(num[i], i));
    } else {
      v.push_back(pair<string, int>(num[i / 10] + " " + num[i % 10], i));
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (i % 10 == 9 || i == v.size() - 1) {
      printf("%d\n", v[i].second);
    } else {
      printf("%d ", v[i].second);
    }
  }
}