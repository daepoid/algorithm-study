#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  string str;
  getline(cin, str);
  for (int i = 0; i < n; i++) {
    getline(cin, str);
    bool flag = true;
    for (int j = 0; j < str.length() / 2; j++) {
      if (tolower(str[j]) == tolower(str[str.length() - 1 - j])) {
      } else {
        flag = false;
        break;
      }
    }
    if (flag) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}