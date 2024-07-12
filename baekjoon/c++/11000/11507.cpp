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

int cards[4][13];

int main() {
  string str;
  cin >> str;
  int a = -1, cnt[4] = {13, 13, 13, 13};
  for (int i = 0; i < str.length(); i = i + 3) {
    switch (str[i]) {
    case 'P':
      a = 0;
      break;
    case 'K':
      a = 1;
      break;
    case 'H':
      a = 2;
      break;
    case 'T':
      a = 3;
      break;
    }
    cards[a][(str[i + 1] - '0') * 10 + str[i + 2] - '0']--;
    if (cards[a][(str[i + 1] - '0') * 10 + str[i + 2] - '0'] < -1) {
      printf("GRESKA\n");
      return 0;
    }
    cnt[a]--;
  }
  for (int i = 0; i < 4; i++) {
    if (i != 3) {
      printf("%d ", cnt[i]);
    } else {
      printf("%d\n", cnt[i]);
    }
  }
}