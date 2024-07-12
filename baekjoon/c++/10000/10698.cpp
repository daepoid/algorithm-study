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
  int n;
  string str;
  scanf("%d", &n);
  getline(cin, str);
  for (int i = 0; i < n; i++) {
    getline(cin, str);
    int a = -1, b = -1, c = -1, op = -1;
    int temp = 0;
    for (int j = 0; j < str.length(); j++) {
      if (isdigit(str[j])) {
        temp = temp * 10 + str[j] - '0';
      } else if (str[j] == ' ') {
        if (a == -1) {
          a = temp;
          temp = 0;
        } else if (b == -1) {
          b = temp;
          temp = 0;
        }
      } else if (str[j] == '+') {
        op = 1;
        j++;
        temp = 0;
      } else if (str[j] == '-') {
        op = 2;
        j++;
        temp = 0;
      } else if (str[j] == '=') {
        j++;
        temp = 0;
      }
    }
    c = temp;
    if (op == 1) {
      printf("Case %d: ", i + 1);
      if (a + b == c) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    } else if (op == 2) {
      printf("Case %d: ", i + 1);
      if (a - b == c) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
}