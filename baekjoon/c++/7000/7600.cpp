#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

bool alpha[26];

int main() {
  string str;
  int cnt;
  while (true) {
    getline(cin, str);
    cnt = 0;
    for (int i = 0; i < 26; i++) {
      alpha[i] = false;
    }
    if (str.compare("#") == 0) {
      break;
    }
    for (int i = 0; i < str.length(); i++) {
      if (isalpha(str[i]) && !alpha[tolower(str[i]) - 'a']) {
        alpha[tolower(str[i]) - 'a'] = true;
        cnt++;
      }
    }
    printf("%d\n", cnt);
  }
}