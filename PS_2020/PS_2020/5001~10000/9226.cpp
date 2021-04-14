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
  int i = 0;
  while (true) {
    char str[21];
    int i = 0;
    scanf("%s", str);
    if (str[0] == '#') {
      return 0;
    }
    for (i = 0; i < strlen(str); i++) {
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
          str[i] == 'u') {
        break;
      }
    }
    if (i == strlen(str)) {
      printf("%say\n", str);
    } else {
      printf("%s", &str[i]);
      for (int j = 0; j < i; j++) {
        printf("%c", str[j]);
      }
      printf("ay\n");
    }
  }
}