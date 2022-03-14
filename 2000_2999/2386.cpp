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
  char c;
  int cnt;
  string line;
  while (true) {
    scanf("%c", &c);
    cnt = 0;
    if (c == '#') {
      return 0;
    }
    getline(cin, line);
    for (int i = 0; i < line.length(); i++) {
      if (c == line[i] || toupper(c) == line[i]) {
        cnt++;
      }
    }
    printf("%c %d\n", c, cnt);
  }
}