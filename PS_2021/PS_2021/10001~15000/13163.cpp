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
    string temp = "", godword = "god";
    bool flag = false;
    for (int i = 0; i < str.length(); i++) {
      if (i == str.length() - 1) {
        temp += str[i];
        godword += temp;
      } else if (str[i] == ' ' && flag) {
        godword += temp;
        temp = "";
      } else if (str[i] == ' ' && !flag) {
        temp = "";
        flag = true;
      } else if (str[i] != ' ') {
        temp += str[i];
      }
    }
    cout << godword << "\n";
  }
}