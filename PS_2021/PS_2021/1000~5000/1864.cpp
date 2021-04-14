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
  int sum, num;
  string str;
  while (true) {
    sum = 0;
    cin >> str;
    if (str[0] == '#') {
      return 0;
    }
    for (int i = 0; i < str.length(); i++) {
      num = 0;
      switch (str[str.length() - i - 1]) {
      case '/':
        num = -1;
        break;
      case '%':
        num++;
      case '&':
        num++;
      case '>':
        num++;
      case '?':
        num++;
      case '@':
        num++;
      case '(':
        num++;
      case '\\':
        num++;
      case '-':
        break;
      default:
        break;
      }
      sum += pow(8, i) * num;
    }
    printf("%d\n", sum);
  }
}