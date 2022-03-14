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

set<int> s, null_s;
set<int> all_s = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
int n, val;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char str[8];
    scanf("%s", str);
    if (str[0] == 'a' && str[1] == 'd') {
      scanf("%d", &val);
      s.insert(val);
    } else if (str[0] == 'r') {
      scanf("%d", &val);
      if (s.find(val) == s.end()) {
        continue;
      }
      s.erase(val);
    } else if (str[0] == 'c') {
      scanf("%d", &val);
      if (s.find(val) != s.end()) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else if (str[0] == 't') {
      scanf("%d", &val);
      if (s.find(val) != s.end()) {
        s.erase(val);
      } else {
        s.insert(val);
      }
    } else if (str[0] == 'a' && str[1] == 'l') {
      s.clear();
      s = all_s;
    } else if (str[0] == 'e') {
      s.clear();
    }
  }
}