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
  int k, h;
  char str[101];
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &h);
    scanf("%s", str);
    for (int j = 0; j < strlen(str); j++) {
      if (str[j] == 'c') {
        h++;
      } else if (str[j] == 'b') {
        h--;
      }
    }
    printf("Data Set %d:\n", i + 1);
    printf("%d\n\n", h);
  }
}