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
  string str, line = "";
  cin >> str;
  for (int i = 1; i <= stoi(str); i++) {
    line += to_string(i);
  }
  printf("%d\n", line.find(str) + 1);
}