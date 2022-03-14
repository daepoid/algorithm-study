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
  while (true) {
    bool flag = true;
    string str;
    getline(cin, str);
    if (str[0] == '*' && str.length() == 1) {
      return 0;
    }
    for (int i = 1; i < str.length(); i++) {
      if (str[i] == ' ' && tolower(str[0]) != tolower(str[i + 1])) {
        flag = false;
      }
    }
    if (flag) {
      printf("Y\n");
    } else {
      printf("N\n");
    }
  }
}