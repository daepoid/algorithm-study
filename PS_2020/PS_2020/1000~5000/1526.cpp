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
  while (true) {
    if (n < 4) {
      return 0;
    }
    string num = to_string(n);
    for (int i = 0; i < num.length(); i++) {
      if (i == num.length() - 1 && (num[i] == '7' || num[i] == '4')) {
        cout << num << endl;
        return 0;
      } else if (num[i] != '7' && num[i] != '4') {
        break;
      }
    }
    n--;
  }
}