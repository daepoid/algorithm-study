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

string sum(string a, string b) {
  int upper = 0;
  string temp = "";
  for (int i = a.length() - 1; i >= 0; i--) {
    if (a[i] - '0' + b[i] - '0' + upper > 9) {
      temp += (a[i] - '0' + b[i] + upper - 10);
      upper = 1;
    } else {
      temp += a[i] - '0' + b[i] + upper;
      upper = 0;
    }
  }
  reverse(temp.begin(), temp.end());
  return temp;
}

string sub(string a, string b) {
  // a - b
  int upper = 0;
  string temp = "";
  for (int i = a.length() - 1; i >= 0; i--) {
    if (a[i] - b[i] - upper < 0) {
      temp += a[i] - b[i] + 10 - upper + '0';
      upper = 1;
    } else {
      temp += a[i] - b[i] - upper + '0';
      upper = 0;
    }
  }
  reverse(temp.begin(), temp.end());
  return temp;
}

int main() {
  string a, b;
  cin >> a >> b;
  if (a[0] != '-' && b[0] == '-') {
    swap(a, b);
  }
  if (a[0] == '-' && b[0] == '-') {
    if (a.length() == b.length()) {
      string temp1 = a.substr(1, a.length());
      string temp2 = b.substr(1, b.length());
      cout << "-" << sum(temp1, temp2) << "\n";
      return 0;
    } else if (a.length() < b.length()) {
      swap(a, b);
    }
    string temp1 = a.substr(1, a.length());
    string temp2;
    for (int i = 0; i < a.length() - b.length(); i++) {
      temp2 += "0";
    }
    for (int i = 1; i < b.length(); i++) {
      temp2 += b[i];
    }
    cout << "-" << sum(temp1, temp2) << "\n";
    //  동작
  } else if (a[0] == '-' && b[0] != '-') {
    if (a.length() - 1 == b.length()) {
      string temp = a.substr(1, a.length());
      if (temp < b) {
        swap(temp, b);
      } else {
        cout << "-";
      }
      cout << sub(temp, b) << "\n";
    } else if (a.length() - 1 > b.length()) {
      string temp = a.substr(1, a.length());
      string temp2;
      for (int i = 0; i < a.length() - b.length() - 1; i++) {
        temp2 += "0";
      }
      for (int i = 0; i < b.length(); i++) {
        temp2 += b[i];
      }
      string ans = sub(temp, temp2);
      int idx;
      for (idx = 0; idx < ans.length(); idx++) {
        if (ans[idx] != '0') {
          break;
        }
      }
      ans = ans.substr(idx, ans.length());
      cout << "-" << ans << "\n";
    } else {
      string temp = a.substr(1, a.length());
      string temp2;
      for (int i = 0; i < b.length() - a.length() + 1; i++) {
        temp2 += "0";
      }
      for (int i = 1; i < a.length(); i++) {
        temp2 += a[i];
      }
      string ans = sub(b, temp2);
      int idx;
      for (idx = 0; idx < ans.length(); idx++) {
        if (ans[idx] != '0') {
          break;
        }
      }
      ans = ans.substr(idx, ans.length());
      cout << ans << "\n";
    }
  } else {
    if (a.length() == b.length()) {
      cout << sum(a, b) << "\n";
      return 0;
    } else if (a.length() < b.length()) {
      swap(a, b);
    }
    string temp2;
    for (int i = 0; i < a.length() - b.length(); i++) {
      temp2 += "0";
    }
    for (int i = 0; i < b.length(); i++) {
      temp2 += b[i];
    }
    cout << sum(a, temp2) << "\n";
    //동작
  }
}