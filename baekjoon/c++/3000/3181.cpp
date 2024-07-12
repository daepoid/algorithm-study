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
  string str, temp;
  getline(cin, str);
  vector<string> v;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != ' ') {
      temp += str[i];
    } else {
      v.push_back(temp);
      temp = "";
    }
  }
  v.push_back(temp);
  cout << char(v[0][0] - 'a' + 'A');
  for (int i = 1; i < v.size(); i++) {
    if (v[i] != "i" && v[i] != "pa" && v[i] != "te" && v[i] != "ni" &&
        v[i] != "niti" && v[i] != "a" && v[i] != "ali" && v[i] != "nego" &&
        v[i] != "no" && v[i] != "ili") {
      cout << char(v[i][0] - 'a' + 'A');
    }
  }
}