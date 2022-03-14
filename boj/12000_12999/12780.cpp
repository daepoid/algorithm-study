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
  int cnt = 0;
  string str, s;
  cin >> str;
  cin >> s;
  for (int i = 0; i < str.length() - s.length() + 1; i++) {
    if (str.substr(i, s.length()) == s) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}