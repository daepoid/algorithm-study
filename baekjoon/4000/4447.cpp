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

int main() {
  int n;
  string str;
  scanf("%d", &n);
  getline(cin, str);
  for (int i = 0; i < n; i++) {
    getline(cin, str);
    int point = 0;
    for (int j = 0; j < str.length(); j++) {
      if (str[j] == 'G' || str[j] == 'g') {
        point++;
      } else if (str[j] == 'B' || str[j] == 'b') {
        point--;
      }
    }
    cout << str << " is ";
    if (point > 0) {
      cout << "GOOD" << endl;
    } else if (point < 0) {
      cout << "A BADDY" << endl;
    } else {
      cout << "NEUTRAL" << endl;
    }
  }
}