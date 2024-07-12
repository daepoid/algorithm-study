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
  int k;
  char str[201];
  char ans[201];
  scanf("%d", &k);
  scanf("%s", str);
  for (int i = 0; i < strlen(str) / k; i++) {
    if (i % 2 == 1) {
      reverse(str + i * k, str + (i + 1) * k);
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < strlen(str) / k; j++) {
      printf("%c", str[i + j * k]);
    }
  }
  printf("\n");
}