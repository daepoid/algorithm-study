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
  int n, cnt = 0;
  scanf("%d", &n);
  while (n--) {
    string s, p;
    cin >> s >> p;
    string str = s;
    cnt = 0;
    while (true) {
      if (s.find(p) != string::npos) {
        int it = s.find(p);
        string temp1 = s.substr(0, it);
        string temp2 = s.substr(it + p.length(), s.length());
        s = temp1 + temp2;
        cnt++;
      } else {
        break;
      }
    }
    printf("%d\n", s.length() + cnt);
  }
}