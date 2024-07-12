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
  int len = str.length(), cnt = 0, point = 0;
  sort(str.begin(), str.end());
  do {
    cnt = 0;
    for (int i = 0; i < len - 1; i++) {
      if (str[i] != str[i + 1]) {
        cnt++;
      }
    }
    if (cnt == len - 1) {
      point++;
    }
  } while (next_permutation(str.begin(), str.end()));
  printf("%d\n", point);
}