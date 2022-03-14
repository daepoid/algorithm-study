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
  string str;
  while (true) {
    cin >> str;
    if (str == "0") {
      return 0;
    }
    string temp = str;
    reverse(temp.begin(), temp.end());
    if (temp == str) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
}