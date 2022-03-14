#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string x;
  int ans = 0, mod = 0, start = 0;
  cin >> x;
  if (x[0] == '0') {
    if (x[1] == 'x') { // 16
      mod = 16;
      start = 2;
    } else {
      mod = 8;
      start = 1;
    }
    for (int i = start; i < x.length(); i++) {
      if (!isdigit(x[i])) {
        ans += (x[i] - 'a' + 10) * pow(mod, x.length() - 1 - i);
      } else {
        ans += (x[i] - '0') * pow(mod, x.length() - 1 - i);
      }
    }
    printf("%d\n", ans);
  } else {
    cout << x;
  }
}