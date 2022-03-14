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
  int cnt = 0;
  while (true) {
    string num;
    cin >> num;
    if (num == "0") {
      return 0;
    }
    for (cnt = 0; num.length() != 1; cnt++) {
      int sum = 0;
      for (int i = 0; i < num.length(); i++) {
        sum += num[i] - '0';
      }
      num = to_string(sum);
    }
    cout << num << "\n";
  }
}