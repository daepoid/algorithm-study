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
  char num[101];
  scanf("%d", &n);
  while (n-- > 0) {
    scanf("%s", num);
    if ((num[strlen(num) - 1] - '0') % 2 == 0) {
      printf("even\n");
    } else {
      printf("odd\n");
    }
  }
}