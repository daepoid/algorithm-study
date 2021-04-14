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
  string a, b, c;
  bool A, B, C;
  cin >> a >> b >> c;
  if (a == "true") {
    A = true;
  } else {
    A = false;
  }
  if (c == "true") {
    C = true;
  } else {
    C = false;
  }
  if (b == "OR") {
    cout << boolalpha << (A || C) << endl;
  } else if (b == "AND") {
    cout << boolalpha << (A && C) << endl;
  }
}