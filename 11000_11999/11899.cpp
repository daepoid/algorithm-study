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
  string str;
  cin >> str;
  int cnt = 0, point = 0;
  for (int i = 0; i < str.length(); i++) {
    if (cnt <= 0 && str[i] == ')') {
      point++;
    } else if (str[i] == '(') {
      cnt++;
    } else if (cnt > 0 && str[i] == ')')
      cnt--;
  }
  printf("%d\n", point + cnt);
}