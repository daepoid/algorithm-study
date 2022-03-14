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
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    int len = sqrt(str.length());
    for (int a = len - 1; a >= 0; a--) {
      for (int b = 0; b < len; b++) {
        printf("%c", str[b * len + a]);
      }
    }
    printf("\n");
  }
}