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
  int a, b;
  while (scanf("%d %d", &a, &b) != EOF) {
    int cnt = 0;
    for (int i = a; i <= b; i++) {
      string num = to_string(i);
      bool flag[10];
      memset(flag, false, sizeof(flag));
      for (int j = 0; j < num.length(); j++) {
        if (!flag[num[j] - '0'] && j == num.length() - 1) {
          cnt++;
        } else if (!flag[num[j] - '0']) {
          flag[num[j] - '0'] = true;
        } else {
          break;
        }
      }
    }
    printf("%d\n", cnt);
  }
}