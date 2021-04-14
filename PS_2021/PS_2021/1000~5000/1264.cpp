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
  while (true) {
    int cnt = 0;
    getline(cin, str);
    if (str == "#") {
      return 0;
    }
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
          str[i] == 'u') {
        cnt++;
      } else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
                 str[i] == 'O' || str[i] == 'U') {
        cnt++;
      }
    }
    printf("%d\n", cnt);
  }
}