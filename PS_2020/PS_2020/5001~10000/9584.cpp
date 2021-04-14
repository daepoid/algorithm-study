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
  int cnt = 0, t;
  string str;
  vector<string> v;
  cin >> str;
  scanf("%d", &t);
  while (t-- > 0) {
    string s;
    cin >> s;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] != '*' && str[i] == s[i]) {
        if (i == str.length() - 1) {
          v.push_back(s);
          cnt++;
        }
      } else if (str[i] != '*' && str[i] != s[i]) {
        break;
      } else if (str[i] == '*' && i == str.length() - 1) {
        v.push_back(s);
        cnt++;
      }
    }
  }
  printf("%d\n", cnt);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}