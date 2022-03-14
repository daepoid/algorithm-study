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
  int n;
  scanf("%d", &n);
  string str;
  getline(cin, str);

  while (n-- > 0) {
    getline(cin, str);
    if (str.length() < 10) {

    } else {
      if (str.substr(0, 10).compare("Simon says") == 0) {
        cout << str.substr(10, str.length() - 10) << endl;
      }
    }
  }
}