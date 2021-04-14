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
  bool a[3] = {true, false, false};
  char str[51];
  scanf("%s", str);
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == 'A') {
      swap(a[0], a[1]);
    } else if (str[i] == 'B') {
      swap(a[1], a[2]);
    } else if (str[i] == 'C') {
      swap(a[0], a[2]);
    }
  }
  if (a[0]) {
    printf("1\n");
  } else if (a[1]) {
    printf("2\n");
  } else {
    printf("3\n");
  }
}