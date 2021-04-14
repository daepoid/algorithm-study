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

int alpha[26];

int main() {
  int cnt = 0, pos;
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    alpha[str[i] - 'A']++;
  }
  for (int i = 0; i < 26; i++) {
    if (alpha[i] % 2 == 1) {
      cnt++;
    }
  }
  if (cnt > 1) {
    printf("I'm Sorry Hansoo\n");
    return 0;
  }

  string temp = "";
  for (int i = 0; i < 26; i++) {
    while (alpha[i] > 1) {
      temp += ('A' + i);
      alpha[i] -= 2;
    }
  }
  string temp2 = temp;
  reverse(temp2.begin(), temp2.end());
  for (int i = 0; i < 26; i++) {
    if (alpha[i] == 1) {
      temp += ('A' + i);
    }
  }
  cout << temp << temp2 << "\n";
}